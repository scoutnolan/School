#!/bin/bash
module load gcc
#redirect standard out to histogram_gnu.txt file
./histogram_PTH_gnu 10000 4 100 0 y >histogram_PTH_gnu.txt
