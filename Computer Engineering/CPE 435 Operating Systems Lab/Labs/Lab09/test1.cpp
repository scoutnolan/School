/* 
File: test1.cpp 
compile as g++ test1.cpp -o test1 
*/ 
using namespace std; 
#include <iostream> 
main() 
{ 
	int array[1000][1000]; 
	int i,j; 
	for(i=0;i<1000;i++) 
		for(j=0;j<1000;j++) 
			array[i][j]=0; 
			
	cout << "array[0][0] was " << array[0][0] << endl; 
}
