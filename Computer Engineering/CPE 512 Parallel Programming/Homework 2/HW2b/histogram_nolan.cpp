/*  Compilation on dmc.asc.edu

   GNU Compiler
   module load gcc
   g++ histogram.cpp -o histogram -std=c++11 -fopenmp

To execute:
   
   GNU compiler
   run_script histogram_gnu.sh
*/  

using namespace std;
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <random>
#include <exception>
#include <string.h>
#include <omp.h>

double *numbers;
int *histogram;
double max_val, min_val,bin_range;

struct data{
   int  start;
   int  end;
   int* local_hist;
}; 


/*
Function used by get_parameters routine to prompt the user to 
interactively enter the next parameter and to return it to the 
calling routine
*/
template <class T>
T enter_next_param(const std::string prompt) {
   T num;
   while (1) {
      string input = "";
      cout << prompt << endl;
      getline(cin, input);
      stringstream myStream(input);
      if (myStream >> num) break;
      cout << "Invalid Input" << endl << endl;
   }
   return num;
}

/*
Routine to retrieve the run time parameters which include
1) the number of numbers in the number list,
2) number of equally spaced bins to be used by the histogram,
3) maximum value in bin range, 4) minimum value in bin range.
If there is a 5th run time parameter then outputing of the numbers 
array that was generated is suppressed 
If no parameters are supplied on the command line, then the program
interactively prompts the user for the information.
*/
void get_parameters(int *list_size,int *num_bins,double *max_bin_val, 
   double *min_bin_val,bool *num_list_out, int argc,char *argv[]) {

   if(argc==1) {
      // One Command Line Argument Case:
      // case where user did not enter number of numbers on command line
      *list_size=enter_next_param<int>("Enter number of numbers in list:");
      *num_bins=enter_next_param<int>("Enter number of bins in histogram:");
      *max_bin_val=enter_next_param<double>("Enter Upper Range of histogram:");
      *min_bin_val=enter_next_param<double>("Enter Lower Range of histogram:");
      char print_out=enter_next_param<char>("Suppress numbers array printing (y or n):");
      if (print_out=='y' || print_out=='Y') *num_list_out=false; 
   }
   else if (argc==5 || argc==6) {
      *list_size = atoi(argv[1]); // get list_size from command line
      *num_bins = atoi(argv[2]);  // get num_bins from command line
      *max_bin_val = atoi(argv[3]);  // get max_bin_val from command line
      *min_bin_val = atoi(argv[4]);  // get min_bin_val from command line
      if (argc==6) *num_list_out=false; // suppress output of numbers array
   }
   else {
      cout << "Usage: " << argv[0] << 
         " [list size num_bins max_bin_val min_bin_val]" 
         << endl;
      exit(1);
   }
}

/*
Routine that fills a 1-D array with Random Data with values
based on a normal distibution that has a mean of MEAN and a
standard deviation of STDEV
This simulates in some way what might happen if there was a 
single sequential data acquisition source.
*/
#define MEAN  50.0f
#define STDEV 20.0f
void create_list(double *numbers,int list_size) {
   std::default_random_engine generator(123546);
   std::normal_distribution<double> distribution(MEAN,STDEV);

   for(int i=0;i<list_size;i++) {
      numbers[i]=distribution(generator);
   }
}

// Routine that outputs the numbers matrix to the screen 
void print_matrix(double *numbers,int list_size)
{
   for(int i=0;i<list_size;i++) {
      cout << numbers[i] << endl;
   }
}

// MAIN ROUTINE: serial histogram calculation
int main(int argc, char *argv[]) {
   int list_size;
   int num_bins;
   bool print_flg=true; // default is to print numbers out to screen

   int nthreads = 1; // default is 1 if env variable is not set
   char *env_var;
   if ((env_var=getenv("OMP_NUM_THREADS"))!=NULL) {
      nthreads=atoi(env_var);
   }
   else if ((env_var=getenv("PTH_NUM_THREADS"))!=NULL) {
            nthreads=atoi(env_var);
   }

   get_parameters(&list_size,&num_bins,&max_val,&min_val,&print_flg,
      argc,argv);
   // compute the range associated with each bin
   bin_range = (max_val-min_val)/num_bins;


   // dynamically allocate the histogram array 
   try {
      histogram = new int[num_bins];
   }
   catch (exception& err) { 
      cout << err.what() << " on for histogram "
           << "array :(" << endl << flush;
   }

   // dynamically allocate the numbers array 
   try {
      numbers = new double[list_size];
   }
   catch (exception& err) { 
      cout << err.what() << " on numbers "
           << "array :(" << endl << flush;
   }

   // initialize numbers array with random data
   create_list(numbers,list_size);

   // print the array if printing is enabled
   if (print_flg) { 
      cout << "numbers matrix =" << endl; 
      print_matrix(numbers,list_size);
      cout << endl;
   }

   // create histogram from the set of numbers

   // clear out histogram array
   omp_set_num_threads(nthreads);
   data args[nthreads];
   for (int i=0;i<num_bins;i++) histogram[i]=0;
   for(int i = 0; i < nthreads; i++) args[i].local_hist = new int[num_bins];
   
   int s = 0;

   // Compute start and end position for each thread.
   for(int t = 0; t < nthreads; t++){
      if(t < (list_size % nthreads)){
         int n = list_size/nthreads + 1;
         args[t].start = s;
         args[t].end = s + n - 1;
      }
      else{
         int n = list_size/nthreads;
         args[t].start = s; 
         args[t].end = s + n - 1;
      }
      s = args[t].end + 1;
   }

   int tnum; // thread number
   int numt; // number of threads

   #pragma omp parallel private(tnum)
   {
      tnum = omp_get_thread_num();
      numt = omp_get_num_threads();

      // compute the histogram for the set of numbers
      #pragma omp parallel for
      for (int i = args[tnum].start; i <= args[tnum].end; i++) {
         double num = numbers[i];
         if (num>=min_val && num < max_val) {
            num -= min_val;
            int bin_num = (int) (num/bin_range);
            args[tnum].local_hist[bin_num]++;
         }
      }

      // Join the global back together.
      #pragma omp parallel for
      for(int j = 0; j < num_bins; j++){
         histogram[j] = histogram[j] + args[tnum].local_hist[j];
      }
   }

   // output histogram
   cout << "Histogram Information" << endl;
   for (int i=0;i<num_bins;i++) {
      cout << setprecision(8) << min_val+bin_range/2+bin_range*i <<
          "  " << histogram[i] << endl;
    }
    cout << flush;

   // reclaim dynamiclly allocated memory
   delete histogram;
   delete numbers;
}

