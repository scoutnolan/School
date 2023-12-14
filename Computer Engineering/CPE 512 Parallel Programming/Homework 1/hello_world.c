/* Simple Hello World Program C Version
FILE: hello_world.c

Compilation on dmc.asc.edu

   to compile the program

     Using GNU Compiler
     module load gcc
     gcc hello_world.c -o hello_world_gnu

     Using Intel Compiler
     module load intel/19.0.4.243
     icc hello_world.c -o hello_world_intel

     Using NVIDIA hpc Compiler
     module load pgi
     pgcc hello_world.c -o hello_world_hpc
*/
#include <stdio.h>
int main (int argc, char *argv[]) {
   #ifdef __PGI
      // Compiled with the NVIDA HPC Compiler
      printf("Hello world from NVIDA HPC compiler\n");
      fflush(stdout);
   #elif  __INTEL_COMPILER
      // Compiled with Intel Compiler
      printf("Hello world from Intel compiler\n");
      fflush(stdout);
   #elif __GNUC__
      // Compiled with GNU Compiler
      printf("Hello world from GNU compiler\n");
      fflush(stdout);
   #endif
}
