#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct process
{
	int pid;		//
	int btimeor;
	int btime;		// Burst time
	int priority;	//
	int wtime;		// Working time
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
	//Assuming ./pbt n 

	int n = atoi(argv[1]); // number of P
	struct process * P = malloc(sizeof(struct process) * n);
	int avgwait = 0;
	int count = 0;
	int count2 = 0;
	int procRemain = n;
	
	// pid0 pbt0 priority0 pid1 pbt1 priority1 ...
	printf("Enter ID, burst time and finally priority.\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &P[i].pid);
		scanf("%d", &P[i].btime);
		P[i].btimeor = P[i].btime;
		scanf("%d", &P[i].priority);
	}

	// sort P by priority using qsort
	// Finding waiting times
	int prio = 1;
	while(procRemain != 0)
	{
		for(int i = 0; i < n; i++)
		{
			if (P[i].priority == prio)
			{
				printOrder(P[i].pid, P[i].btime);
				for(int j = 0; j < n; j++)
				{
					if(i != j)
					{
						if(P[j].btime > 0)
						{
							P[j].wait_t += P[i].btime;
						}
					}
				}
				P[i].btime = 0;
				prio++;
			}
		}	
		procRemain--;
	}

	// Finding average wait time
	for (int i = 0; i < n; i++)
		avgwait += P[i].wait_t;
	avgwait = avgwait / n;
	
	// Finding turn around times
	for (int i = 0; i < n; i++)
		P[i].rtime = P[i].btimeor + P[i].wait_t;

	// Print results

	printf("-------------------------------------------------\n");
	printf("|Process|PID\t|Burst\t|Turn\t|Wait\t|Priority\n");
	for (int i = 0; i < n; i++)
	{
		printf("|%d\t|%d\t|%d\t|%d\t|%d\t|%d\n",
		i, P[i].pid, P[i].btimeor, P[i].rtime, P[i].wait_t, P[i].priority);
	}
	printf("Average Wait Time: %d\n", avgwait);
	void free(void*);
}
