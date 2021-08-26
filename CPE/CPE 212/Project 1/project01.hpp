#ifndef PROJECT01_HPP
#define PROJECT01_HPP


#include <string>
#include <iostream>
#include <fstream>

const unsigned int MAX_ROWS = 15;
const unsigned int MAX_COLS = 15;


enum Direction
{
    D_Horizontal = -1,  // causes a horizontal flip around the center line
    D_Vertical = 1      // causes a vertical flip around the center line
};

enum Rotation
{
    R_Clock = -1,       // causes a 90 degree rotation Clockwise
    R_CounterClock = 1  // causes a 90 degree rotation CounterClockwise
};

typedef int Image[MAX_ROWS][MAX_COLS];


// load the image matrix from the file described.
// if an error is ever encountered, this should return false
// if the image is successfully loaded with 0 errors, this
// should return true.
//
// This probably should be the first function you work on.  
// if this function doesn't function correctly then your
// project is dead in the water.
bool LoadImage(const std::string & imageFile, Image image);

// This will flip the matrix according to the direction provided.
// a value of false is returned when an unknown Flip value is given
// otherwise a value of true is returned.
bool Flip(Image image, Direction d);

// this will rotate the matrix according to the direction provided.
// a value of false is returned when an unknown Rotation value is given
// otherwise a value of true is returned.
bool Rotate(Image image, Rotation r);

// this will transpose the image, which flips it across the diagonal.
// this diagonal goes from the top left to the bottom right.
void Transpose(Image image);


#endif // end define PROJECT01_HPP
