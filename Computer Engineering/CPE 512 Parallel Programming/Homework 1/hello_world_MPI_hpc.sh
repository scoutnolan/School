#!/bin/bash
module load openmpi/4.0.5-pgi-pmi2
#redirect standard out to hello_world_MPI_hpc.txt file
srun --mpi=pmi2 ./hello_world_MPI_hpc >hello_world_MPI_hpc.txt
