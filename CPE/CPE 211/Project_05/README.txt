Project 5 Input file information:

These files contain the data that is to be read by the program.
They cannot be used with input redirection.  When the program
prompts the user for the name of a file these are the file names
that are entered.

The following is a list of the input files and what they test
The first three files are all valid inputs, and they are used to
verify that all calculations are correct.  These three files check 
each parcel type, each possible length region and each possible 
weight region.  If the if-then-else-if setup is used for choosing
the various factors, these three tests will test all code for 
determining the shipping cost for any valid package specified.

P7_in1.txt - parcel, length < 40, weight < 10  // first condition on all tests
P7_in2.txt - media, length = 40, weight = 10  // tests middle boundary conditions 
P7_in3.txt - bulk, length = 60, weight = 25  // tests upper boundary condition

NOTE: if you do not use if-then-else-if statements to determine the rates
based off of the valid data entered, then your number of test files can reach a maximum
of 27 different files to completely check your code. 

These next files are used to test for invalid cases
P7_in4.txt - tests invalid package type
P7_in5.txt Invalid character in any of the values for length, width, height and weight
P7_in6.txt - Negative length
P7_in7.txt - Negative width
P7_in8.txt - Negative height
P7_in9.txt - Negative weight

An invalid input file is tested using the name P7_in14.txt since
That input file does not exist.

The empty file test is performed with P7_in10.txt

The following invalid files have possible errors in all areas checked.
These files will show if the error checking is being done in the order 
described by the project description

P7_in11.txt - all entry types have an error - media type, invalid character in
package parameters and negative package parameter

P7_in12.txt - media type is valid, have an invalid character in package
parameters and negative package parameter

P7_in13.txt - media type is valid, all characters in package parameters are
valid, has a negative package parameter 
