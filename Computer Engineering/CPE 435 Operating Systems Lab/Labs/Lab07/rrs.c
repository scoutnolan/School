#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct process
{
	int pid;		// 
	int btime;		// Burst time
	int btimeor;	// Original burst time.
	int rtime; 		// Turn around time
	int wait_t; 	// Wait Time = Turn around Time - Burst Time
};

void printOrder(int pid, int time)
{
	printf("PID of %d ran for %d", pid, time);
	printf("\n");
}

int main(int argc, char* argv[])
{
	// Assuming ./rrs n qtu 
	int n = atoi(argv[1]); 		// number of P
	int qtu = atoi(argv[2]); 	// quantum time unit
	struct process* P = malloc(sizeof(struct process) * n);
	int pid_and_pbt[n]; // array for PID and PBT values
	int avgwait = 0;
	int remainProc = n;
	
	// pid0 pbt0 pid1 pbt1 ...
	printf("Enter ID and then burst time \n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &P[i].pid);
		scanf("%d", &P[i].btime);
		P[i].btimeor = P[i].btime;
	}
	printf("-------------------------------------\n");

	// Finding wait times
	while (remainProc != 0)
	{
		for(int i = 0; i < n; i++)	// For each process 
		{
			if(P[i].btime > 0)	// If the burst time is greater than 0
			{
				if(P[i].btime > qtu)	// If the burst time greater than qtu
				{
					P[i].btime -= qtu;	// Subtract qtu from process burst time.
					for(int j = 0; j < n; j++)	// For all the other processes.
					{
						if(P[j].btime > 0)
							P[j].rtime += qtu; // Add qtu to the turn around time.
					}
					printOrder(P[i].pid, qtu);
				}
				else if(P[i].btime <= qtu)	// btime is less than qtu, add to t. 
				{
					for(int j = 0; j < n; j++)	
					{
						if(P[j].btime > 0)
							P[j].rtime += P[i].btime; // Add qtu to the turn around time.
					}
					printOrder(P[i].pid, P[i].btime);
					P[i].btime = 0;	// Set burst time to 0, no longer need
					remainProc--; 	// Since btime is empty, process won't run again.
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++)
		P[i].wait_t = P[i].rtime - P[i].btimeor;	// Wait = turn around - burst time.

	for (int i = 0; i < n; i++)
		avgwait += P[i].wait_t;
	avgwait = avgwait / n;

	// Print results
	printf("-------------------------------------\n");
	printf("|Process|PID\t|Burst\t|Turn\t|Wait\n");
	for (int i = 0; i < n; i++)
	{
		printf("|%d\t|%d\t|%d\t|%d\t|%d\n",
		i, P[i].pid, P[i].btimeor, P[i].rtime, P[i].wait_t);
	}
	printf("Quantum Time Unit: %d\n", qtu);
	printf("Average Wait Time: %d\n", avgwait);
	void free(void*);
}