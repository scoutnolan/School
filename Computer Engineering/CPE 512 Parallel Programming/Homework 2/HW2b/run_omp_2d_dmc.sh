#!/bin/bash
# This script calls the run_script_omp utility six times to schedule 
# the serial reference simulation and the five other multithreaded OpenMP
# simulations (1, 2, 4, 8, and 16 threads). 
# The script requests the number of core processes equal the number
# of threads that are to be executed on the dmc 
#
# Re-compile source files (serial & OpenMP versions)
# Re-compiling Reference Source File
if test -f "./heat_2d_serial.cpp" 
  then
  echo "Recompiling Reference Serial Source file heat_2d_serial.cpp"
  echo "g++ heat_2d_serial.cpp -o heat_2d_serial -std=c++11 -O3"
  g++ heat_2d_serial.cpp -o heat_2d_serial_gnu -std=c++11 -O3
  echo "complete!"
else
  if test -f "./heat_2d_serial.c" 
    then
    echo "Recompiling Source file heat_2d_serial.c"
    echo "gcc heat_2d_serial.c -o heat_2d_serial -O3"
    mpicc heat_2d_serial.c -o heat_2d_serial_gnu -O3
    echo "complete!"
  else
    echo "No valid serial source file found!"
    echo "Looking for file heat_2d_serial.cpp, or heat_2d_serial.c"
    echo "to compile"
    exit
  fi  
fi  
# Re-compiling OpenMP Source File
if test -f "./heat_2d_OMP.cpp" 
  then
  echo "Recompiling Source file heat_2d_OMP.cpp"
  echo "g++ heat_2d_OMP.cpp -o heat_2d_OMP_gnu -std=c++11 -O3 -fopenmp"
  module load gcc
  g++ heat_2d_OMP.cpp -o heat_2d_OMP_gnu -std=c++11 -O3 -fopenmp
  echo "complete!"
else
  if test -f "./heat_2d_OMP.c" 
    then
    echo "Recompiling Source file heat_2d_OMP.c"
    echo "gcc heat_2d_OMP.c -o heat_2d_OMP_gnu  -O3 -fopenmp"
    module load gcc
    gcc heat_2d_OMP.c -o heat_2d_OMP_gnu -std=c99 -O3 -fopenmp
    echo "complete!"
  else
    echo "No valid source file found! -- very bad indead!!"
    echo "Looking for file heat_2d_OMP.cpp or heat_2d_OMP.c to compile"
    exit
  fi  
fi  
# copy general scripts to the current directory
echo "Copying plot scripting files to current directory"
cp /home/shared/wells_class/OMP_Examples/2D_heat_transfer/.scripts/* . 

# Check for script run time arch constraint parameter
if test $# -ne 0
  then
  constraint=$1
else
  constraint="ivy-bridge"
fi
echo "Architectural Constraint: "$constraint
echo

# Serial Reference Run
# Number of Nodes: 1 
# Script File: heat_2d_serial_dmc.sh
echo -e "Scheduling Serial Job on the DMC\n"
echo -e "class\n1\n01:00:00\n32gb\n\n"$constraint"\n" | run_script_omp heat_2d_serial_dmc.sh >heat_2d_serial_info.txt
#
# 1 Thread OpenMP Run
# Number of Nodes: 1 
# Script File: heat_2d_pth_1_dmc.sh
echo -e "Scheduling 1 Thread Job on the DMC\n"
echo -e "class\n1\n01:00:00\n32gb\n\n"$constraint"\n" | run_script_omp heat_2d_pth_1_dmc.sh >heat_2d_OMP_1_info.txt
#
# 2 Thread OpenMP Run
# Number of Nodes: 2 
# Script File: heat_2d_pth_2_dmc.sh
echo -e "Scheduling 2 Thread Job on the DMC\n"
# DMC Node Architecture Constraint: first argument
echo -e "class\n2\n01:00:00\n32gb\n\n"$constraint"\n" | run_script_omp heat_2d_pth_2_dmc.sh >heat_2d_OMP_2_info.txt
#
# 4 Thread OpenMP Run
# Number of Nodes: 4 
# Script File: heat_2d_pth_4_dmc.sh
echo -e "Scheduling 4 Thread Job on the DMC\n"
echo -e "class\n4\n01:00:00\n32gb\n\n"$constraint"\n" | run_script_omp heat_2d_pth_4_dmc.sh >heat_2d_OMP_4_info.txt
#
# 8 Thread OpenMP Run
# Number of Nodes: 8 
# Script File: heat_2d_pth_8_dmc.sh
echo -e "Scheduling 8 Thread Job on the DMC\n"
echo -e "class\n8\n01:00:00\n32gb\n\n"$constraint"\n" | run_script_omp heat_2d_pth_8_dmc.sh >heat_2d_OMP_8_info.txt
#
# 16 Thread OpenMP Run
# Number of Nodes: 16 
# Script File: heat_2d_pth_16_dmc.sh
echo -e "Scheduling 16 Thread Job on the DMC\n"
echo -e "class\n16\n01:00:00\n32gb\n\n"$constraint"\n" | run_script_omp heat_2d_pth_16_dmc.sh >heat_2d_OMP_16_info.txt

