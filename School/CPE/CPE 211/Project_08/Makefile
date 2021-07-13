#!/bin/sh
#
# Makefile for project 08
# It is best if you do not modify this file

# the line below creates the project 08 executable named Project_08
# the creation is dependent on the object files for 
# P08_main and Project_08 

Project_08 : P08_main.o Project_08.o 
	g++ -lm -o Project_08 Project_08.o  P08_main.o

# compile the main function that drives the program
P08_main.o : P08.h P08_main.cpp
	g++ -lm -c P08_main.cpp

# compile the functions written by the student
Project_08.o : Project_08.cpp P08.h
	g++ -lm -c Project_08.cpp

# the command <make clean> will remove all files created by this makefile
# this allows for a fresh compile of the program.
clean:
	rm *.o 
	rm  Project_08 

cleanCompare:
	rm *.o Project_08.cpp_run compile_errors.txt 

