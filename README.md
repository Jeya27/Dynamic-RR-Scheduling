# Dynamic-RR-Scheduling

Round Robin (RR) performs optimally in timeshared systems because each process is given an equal amount of static time quantum. 
But the effectiveness of RR algorithm solely depends upon the choice of time quantum. If we choose a very less time quantum then 
the number of context switches will be high, and the efficiency of algorithm is lost. Choosing a very big value as time quantum may 
be similar to FCFS algorithm. Hence, we must choose time quantum is such a way that it is neither too small nor too large. This improved 
version of round robin scheduling chooses time quantum on its own with respect to the no. of processes available. It is computed with the 
help of median and highest burst time. Since we take varying time quantum as per the no. of processes, the context switches are reduced.
Hence, the overall waiting time is reduced. This algorithm gives better result compared to round robin scheduling. 
