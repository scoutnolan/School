/* 
File: test2.cpp 
compile as g++ test2.cpp -o test2 
*/ 
using namespace std; 
#include <iostream> 
main() 
{ 
	int array[1000][1000]; 
	int i,j; 
	for(i=0;i<1000;i++) 
		for(j=0;j<1000;j++) 
			array[j][i]=0;
	cout << "array[0][0] was " << array[0][0] << endl; 
}
