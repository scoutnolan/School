#!/bin/bash
module load openmpi/4.0.3-intel-pmi2
#redirect standard out to hello_world_MPI_intel.txt file
srun --mpi=pmi2 ./hello_world_MPI_intel >hello_world_MPI_intel.txt
