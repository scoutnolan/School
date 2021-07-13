//**************************************************************************************//
// Nolan Anderson
// Project 01
// Inputs header file and text files that are an "image"
// Then the functions below manipulate the "images" after loading them into an array
//**************************************************************************************//

#include "project01.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ************** Load the image **************** //

bool LoadImage(const std::string & imageFile, Image image)
{
	ifstream stream;
	stream.open(imageFile.c_str()); //parameter is a c style string 
	if (!stream.good()) // if the file is not good, then return false
	{
		cout << "File entered was not good" << endl;
		return false;
	}
	stream.ignore(200, '\n'); // ignores the header line
	//stream.ignore(200, '\n');
	for (int rows = 0; rows < MAX_ROWS; rows++)
	{
		for (int column = 0; column < MAX_COLS; column++)
		{
			stream >> image[rows][column];
		}
	}
	stream.close();
	return true; 
}

// ************* Flip the image ************ //

bool Flip(Image image, Direction d)
{
	switch(d)
	{
		// first switch funds the horizontal flip
		case D_Horizontal:
		{
			int col = MAX_COLS-1; // new column attribute
            // only iterate through half of the columns
			for(int i = 0; i < MAX_COLS; i++)
				for(int j = 0; j <= col/2; j++)
				{	
					int t = image[i][j];
					image[i][j] = image[i][col-j];
					image[i][col-j] = t;
				}
		}
        break;
		case D_Vertical:
		{
			int rows = MAX_ROWS-1;
			for(int i = 0; i <= rows/2; i++)
				for (int j = 0; j < MAX_ROWS; j++)
				{
					int t = image[i][j];
					image[i][j] = image[rows-i][j];
					image[rows-i][j] = t;
				}
			// only iterate through half of the rows
		}
		break;
	default:
		cout << "Invalid direction caught" << endl;
    }
    return true;
}

// ********** Rotate the image ************* //

bool Rotate(Image image, Rotation r)
{
	switch(r)
	{
		case R_CounterClock:
        {
            Transpose(image);
			Flip(image, D_Vertical); // net result is a counter clockwise turn
        }
			// use a transpose and a flip
		break;

		case R_Clock:
        {
            Transpose(image); // function call to transpose the image
			Flip(image, D_Horizontal); // and then flip it. net result is a clockwise turn
        }
        break;
		default:
			cout << "Unknown rotation caught" << endl;
			return false;
	}
	return true;
}

// ************ Transpose of the image ********** //

void Transpose(Image image)
{
    Image temp;
    for (int i = 0; i < MAX_ROWS; i++) // first for loop creates a temp array and sets it equal to the image
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
			temp[i][j] = image[i][j];
        }
    }
	for (int i = 0; i < MAX_ROWS; i++) // this loop swaps the rows and columns of image by setting it equal to the temporary array
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
			image[i][j] = temp[j][i];
		}
	}
}