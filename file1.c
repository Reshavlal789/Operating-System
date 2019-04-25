//Program in C by Reshav Lal
//LOVELY PROFESSIONAL UNIVERSITY
//SECTION K17TA

/*
 Considering the arrival time and burst time requirement of the process the scheduler schedules the processes
 by interrupting the processor after every 6 units of time and does consider the completion of the process in
 this iteration. The scheduler than checks for the number of process waiting for the processor and allots the
 processor to the process but interrupting the processor every 10 unit of time and considers the completion of
 the processes in this iteration.
 
The scheduler checks the number of processes waiting in the queue for the processor after the second iteration
and gives the processor to the process which needs more time to complete than the other processes to go in the 
terminated state. The inputs for the number of requirements, arrival time and burst time should be provided by
the user. Consider the following units for reference.
Process    Arrival time    Burst time 
P1            0                 20 
P2            5                 36 
P3            13                19 
P4            26                42
Develop a scheduler which submits the processes to the processor in the defined scenario, and compute the scheduler
performance by providing the waiting time for process, turnaround time for process and average waiting time and turnaround time.

*/


#include<stdio.h> 
#define N 10 
typedef struct 
{ 
int process_id,arrival_time,burst_time,priority;
int q,ready; 
}process_structure; 
int Queue(int t1) 
{if(t1==0||t1==1||t1==2||t1==3) 
return 1; 
else
return 2; 
} 
 int main() 
{ 
int limit,i,temp_process,time,j;int y;
process_structure temp; 
printf("Enter Total Number of Processes:\t"); 
scanf("%d", &limit);  
process_structure process[limit]; 
for(i=0;i<limit;i++) 
{ 
printf("\nProcess ID:\t"); 
scanf("%d",&process[i].process_id); 
printf("Arrival Time:\t"); 
scanf("%d", &process[i].arrival_time); 
printf("Burst Time:\t"); 
scanf("%d", &process[i].burst_time); 
printf("Process Priority:\t"); 
scanf("%d", &process[i].priority); 
temp_process = process[i].priority; 
process[i].q = Queue(temp_process);
process[i].ready = 0; 
}
time=process[0].burst_time; 
for(y=0;y<limit;y++) 
{ for(i=y;i<limit;i++) 
	{
if(process[i].arrival_time<time) 
	{
process[i].ready=1; 
	} 
	} 
for(i=y;i<limit-1;i++) 
	{
for(j=i+1;j<limit;j++) 
	{ 
if(process[i].ready==1&&process[j].ready==1) 
		{ 
if(process[i].q==2 && process[j].q==1) 
			{ 
temp=process[i]; 
process[i]=process[j]; 
process[j]=temp; 
} 
} 
} 
} 
for(i=y;i<limit-1;i++) 
{ 
for(j=i+1;j<limit;j++) 
{
if(process[i].ready==1&&process[j].ready==1) 
{ 
if(process[i].q==1&&process[j].q==1) 
{ 
if(process[i].burst_time>process[j].burst_time) 
{ 
temp=process[i]; 
process[i]=process[j]; 
process[j] = temp; 
} 
else 
{ 
break; 
} 
} 
} 
} 
} 
printf("\nProcess %d:\tTime:\t%d To %d\n",process[y].process_id,time,time+process[y].burst_time); 
time=time+process[y].burst_time; 
for(i=y;i<limit;i++) 
{ 
if(process[i].ready==1) 
{ 
process[i].ready=0; 
} 
} 
} 
return 0; 
}
