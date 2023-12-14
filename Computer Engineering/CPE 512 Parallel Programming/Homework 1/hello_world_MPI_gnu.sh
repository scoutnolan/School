#!/bin/bash
module load openmpi
#redirect standard out to hello_world_MPI_gnu.txt file
srun --mpi=pmi2 ./hello_world_MPI_gnu >hello_world_MPI_gnu.txt
