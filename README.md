# Dynamic-RR-Scheduling

Round Robin (RR) performs optimally in timeshared systems because each process is given an equal amount of static time quantum. 
But the effectiveness of RR algorithm solely depends upon the choice of time quantum. If we choose a very less time quantum then 
the number of context switches will be high, and the efficiency of algorithm is lost. Choosing a very big value as time quantum may 
be similar to FCFS algorithm. Hence, we must choose time quantum is such a way that it is neither too small nor too large. This improved 
version of round robin scheduling chooses time quantum on its own with respect to the no. of processes available. It is computed with the 
help of median and highest burst time. Since we take varying time quantum as per the no. of processes, the context switches are reduced.
Hence, the overall waiting time is reduced. This algorithm gives better result compared to round robin scheduling. 

Algorithm

1. Make a ready queue RQUEUE of the processes submitted for execution.
2. DO steps 3 to 9 WHILE queue RQUEUE becomes empty.
3.  Arrange the processes in REQUEUE in the ascending order of their remaining burst time.
4.  Set the time quantum value equal to the burst time of first process from RQUEUE. 
5. Allocate CPU to first process from RQUEUE for a time interval of up to 1 time quantum. Remove the currently running process from RQUEUE, since it has finished execution and the remaining burst time is zero.
6.  Select the next process from RQUEUE, and allocate CPU for a time interval of up to 1 time quantum.
7. IF the currently running process has finished execution and the remaining CPU burst time of the currently running process is zero, remove it from RQUEUE.
8.  IF the remaining CPU burst time of the currently running process is less than 1 time quantum THEN allocate CPU again to the currently running process for remaining CPU burst time. Remove the currently running process from RQUEUE, since it has finished execution and the remaining burst time is zero. ELSE put it at the tail of RQUEUE.
9.  REPEAT steps 6 to 8 for each process in RQUEUE.


The comparison between Round Robin scheduling and Round Robin scheduling with dynamic time quantum algorithm is shown

Process	  Waiting time	Turnaround Time	Context switches
RR	       40.6	          58.2	            11
DQTRR	     28.8	          46.4	             8
