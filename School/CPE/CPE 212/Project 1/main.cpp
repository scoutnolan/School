#include "project01.hpp"

#include <iostream>
#include <fstream>


// prints the matrix.
// if a 1 is found in the slot, print a "*"
// if a 0 is found int he slot, print a "0"
// if a -1 is found, print a "-"
// otherwise, print an "X"
void Print(const Image image);
void Bars();


int main(int argc, char * const argv[])
{
        
    // Output usage message if test input file name is not provided
    if (argc != 2)
    {
        std::cout << "Usage:\n  project01  <inputfile>\n";
        return -1;
    }
    

    std::ifstream input;
    // Attempt to open test input file -- terminate if file does not open
    input.open(argv[1]);
    if (!input)
    {
        std::cout << "Error - unable to open input file" << std::endl;
        return 1;
    }

    Image image;
    std::string line;
    getline(input, line);

    std::cout << std::endl << line << std::endl << std::endl;
    
    // main loop goes here
    char op;
    input >> op;
    while(input)
    {
        switch(op)
        {
            case '#':
                getline(input, line);
                std::cout << "# " << line << std::endl;
                break;
            case 'p':
                Print(image);
                break;
                
            case 'b':
                Bars();
                break;
                
            case 'i':
            {                
                std::string imageFile;
                input >> imageFile;
                if(!LoadImage(imageFile, image))
                {
                    std::cout << "Invalidly caught a return false";
                }
                break;
            }                
            case '+':
                if(!Rotate(image, R_Clock))
                {
                    std::cout << "Invalidly caught a return false";
                }

                break;
                
            case '-':
                if(!Rotate(image, R_CounterClock))
                {
                    std::cout << "Invalidly caught a return false";
                }
                break;
                
            case 'v':
                if(!Flip(image, D_Vertical))
                {
                    std::cout << "Invalidly caught a return false";
                }
                break;
            case 'h':
                if(!Flip(image, D_Horizontal))
                {
                    std::cout << "Invalidly caught a return false";
                }                
                break;
                
            case 't':
                Transpose(image);
                break;

            default:
                std::cout << "Unrecognized command: " << op << std::endl;
                std::cout << "Terminating" << std::endl;
                return -2;
                break;
                
                
                
        }
        std::cout << std::endl;
        input >> op;
    }
    
    return 0;
}

/// DO NOT MODIFY THIS CODE


void Print(const Image image)
{
    for(int r = 0; r < MAX_ROWS; r++)
    {
        for(int c = 0; c < MAX_COLS; c ++)
        {
            switch(image[r][c])
            {
                case 1:
                    std::cout << "*";
                    break;
                case 0:
                    std::cout << "-";
                    break;
                default: 
                    std::cout << "X";
                    break;
            }
        }
        std::cout << std::endl;
    }
}
    
void Bars()
{
    std::cout << "#################################################################\n"
              << "#################################################################"
              << std::endl;     
}