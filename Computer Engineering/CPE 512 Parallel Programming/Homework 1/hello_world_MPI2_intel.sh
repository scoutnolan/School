#!/bin/bash
#Uses the mpich distribution of MPI which supports C++ bindings
#of MPI functions -- intel compiler
module load mpich
#redirect standard out to hello_world_MPI2_intel.txt file
srun --mpi=pmi2 ./hello_world_MPI2_intel >hello_world_MPI2_intel.txt
