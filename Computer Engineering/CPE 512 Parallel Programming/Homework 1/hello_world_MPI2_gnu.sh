#!/bin/bash
#Uses the mpich distribution of MPI which supports C++ bindings
#of MPI functions -- gnu compiler
module load mpich
#redirect standard out to hello_world_MPI2_gnu.txt file
srun --mpi=pmi2 ./hello_world_MPI2_gnu >hello_world_MPI_gnu.txt
