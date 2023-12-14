/*
  Pthreads Example - Hello World - C Version
File: hello_world_PTH.c
  Compilation on dmc.asc.edu

     Using GNU Compiler
     module load gcc
     gcc hello_world_PTH.c -o hello_world_PTH_gnu -lpthread

     Using Intel Compiler
     module load intel/19.0.4.243
     icc hello_world_PTH.c -o hello_world_PTH_intel -lpthread

     Using NVIDIA hpc Compiler
     module load pgi
     pgcc hello_world_PTH.c -o hello_world_PTH_hpc -lpthread

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t MUTEX; // globaly defined lock variable used to insure
                       // uninterrupted print operations from each thread

// This is the worker thread code
void *hello(void * arg) {
   int myid=*(int *) arg;

   // enter critical region
   pthread_mutex_lock(&MUTEX);

   printf("Hello World, from PThread %d\n", myid);
   fflush(stdout);

   // exit critical region
   pthread_mutex_unlock(&MUTEX);

  return arg;
}

// this is the main thread's code -- it spawns the worker threads and
// then waits for all the worker threads to return before it exits
int main(int argc,char *argv[])
{
   int nthreads=1;                // total number of threads to be launched
                                  //  default nthreads=1
   int tid;                       // tid thread id number
   int errcode;                   // pthread error code

   // get total number of threads to be launched
   // if there is a command line parameter use it to set number of threads
   if (argc>1) {
       nthreads=atoi(argv[1]); // get number of threads from command line 
   }
           // if there is no command line parameter check to see if
   else {  // OMP_NUM_THREADS is set -- if set use this for num threads
      char *env_var;
      if ((env_var=getenv("OMP_NUM_THREADS"))!=NULL) {
         nthreads=atoi(env_var);
      }
      else if ((env_var=getenv("PTH_NUM_THREADS"))!=NULL) {
         nthreads=atoi(env_var);
      }
   }

   // dynamically allocate threads[nthreads] on heap fully C++ compliant manner
   pthread_t *threads = malloc(sizeof(pthread_t)*nthreads); 

   // dynamically allocate ids[nthreads] on heap fully C++ compliant manner
   int *ids = malloc(sizeof(int)*nthreads);

   // initialize mutex variable -- this variable is used to insure that
   // all couts are automic meaning that they are not interrupted
   pthread_mutex_init(&MUTEX,NULL);

   /* create the threads */
   for (tid=0; tid<nthreads; tid++) {
      ids[tid]=tid;
      errcode=pthread_create(
              &threads[tid],// thread information structure
              NULL,         // thread attributes -- NULL means assume defaults 
              hello,        // function name that is to represent thread
              &ids[tid]);  // pthread created thread id for the created thread        
      // check for error during thread creation
      if (errcode) {
         printf("Pthread Creation Error: %s\n",strerror(errcode)); 
         exit(1);
      }
   }

   // print out number of threads
   pthread_mutex_lock(&MUTEX); // enter critical region

   printf("Number of threads = %d\n", nthreads); 
   printf("Program compiled using ");
   #ifdef __PGI
      printf("NVIDA HPC compiler\n"); 
   #elif __INTEL_COMPILER 
      printf("Intel compiler\n"); 
   #elif __GNUC__
      printf("GNU compiler\n"); 
   #endif
   fflush(stdout);

   pthread_mutex_unlock(&MUTEX); // exit critical region

   // wait for all threads to return before exiting main program (process)
   for (tid=0; tid<nthreads; tid++) {
      // wait for each thread to terminate 
      errcode=pthread_join(
              threads[tid], //thread scheduler id information of selected thread
              NULL);        //thread return value -- not used in this case
      if (errcode) {
         printf("Pthread Join Error: %s\n",strerror(errcode)); 
         exit(1);
      }
   }
   free(threads);
   free(ids); 
   return(0);
}
