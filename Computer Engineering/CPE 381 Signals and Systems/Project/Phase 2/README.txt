*********************************************************************************
Name: Nolan Anderson
Course: CPE 381
Assignment: Project 1 Phase 1
Due date: 16 March 2021
Anderson_N_original.wav : The original audio file.
Anderson_N_mod.wav      : The matlab modified wav file.
Anderson_N_filt.wav      : The final audio without noise. 
Anderson_N_Phase1.m     : Matlab script to modify the original wav file.
                            Input: Wav file 
                            Output : Wav file with sin wave attached.
Anderson_N_Phase1.cpp   : C++ script to add noise to our matlab wav file.
                            Input : Matlab Wav file.
                            Output : Matlab wav file with real time random noise.
                            Anderson_N_sum.txt
                            Compilation: UAH Blackhawk servers. Use make file to compile or:
         	                        g++ -g -std=c++11 Anderson_N_Phase1.cpp -o PhaseOneExecutable
                                    All of this is performed in bash.
                            Execution:    
                                    ./PhaseOneExecutable
PhaseOneExecutable      : Executable for Anderson_N_Phase1.cpp.
Anderson_N_sum.txt      : Summary text after executing executable
tmwtypes.h			    : Helper header for filter coeficcients
filter_11025.h / filter_22050.h	: Filter coeficcients. 
*********************************************************************************
