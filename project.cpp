#include<iostream>
#include<math.h>

using namespace std;

int get_tq(int b[],int p[],int s)
{
	int i,j,maxbt,tmp,hbt,median;
	float k,l,m;	
	
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if (b[i]>b[j])
			{
				tmp=b[i];
				b[i]=b[j];
				b[j]=tmp;
				
				tmp=p[i];
				p[i]=p[j];
				p[j]=tmp;
			}
		}
	}
	
	cout<<"Burst time : \n";
//	for(i=0 ; i<s ; i++)
//		cout<<"B["<<i<<"]="<<b[i]<<endl;
	
	hbt=b[i-1];
	median=b[i/2];
	
	l=(float)hbt;
	m=(float)median;
	k=sqrt((l*m));

return(ceil(k));
}

void findWaitingTime(int processes[], int n,int bt[], int wt[],int quantum)
{
    int rem_bt[n];
    int cs=1;
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];
 
 //	int quantum,flag;
 //	int remain=n;
 //	quantum=get_tq(bt,processes,n);
 //	cout<<"Time quantum : "<<quantum<<endl;
 
    int t = 0;

    while (1)
    {
        bool done = true;
        
        for (int i = 0 ; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false; 
 
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                    cs++;
                }
                else
                {
				    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                    cs++;
                    //flag=1;
			   }
			   
	/*		   if(rem_bt[i]==0 && flag==1)
			   {
			   		remain--;
					quantum=get_tq(bt,processes,remain);
					cout<<"Time quantum : "<<quantum<<endl;
			   }*/
            }        
        }          
 	
        if (done == true)
			break;
          
    }
    cout<<"Context switches : " <<cs<<endl;
}
 
void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 
void findavgTime(int processes[], int n, int bt[],int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    
    findWaitingTime(processes, n, bt, wt,quantum);
    
    findTurnAroundTime(processes, n, bt, wt, tat);
 
     cout << "Processes "<< " Burst time " << " Waiting time " << " Turn around time\n";

    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        //cout << " " <<" P[" <<processes[i]<<"]" << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
        //cout<< cs[i] <<endl;        
    }
 
    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}
 
int main()
{
	int processes[600],burst_time[600],cs[600];
	FILE *fp;
	int i;
	
	int n=400;
//	fp=fopen("input.txt","r");
	fp=fopen("500input.txt","r");

//	cout<<"Enter the no. of processes : ";
//	cin>>n;
	
/*	for(i=0 ; i<n ; i++)
	{
		cin>>burst_time[i];
		processes[i]=i+1;
	}
*/		

	while(!feof(fp))
	{
		for(i=0 ; i<n ; i++)
		{
			fscanf(fp,"%d",&burst_time[i]);
			processes[i]=i+1;
		}
	}
	
//	for(i=0 ; i<n ; i++)
//		cout<<processes[i]<<endl;
	
	int quantum=get_tq(burst_time,processes,n);
	cout<<"Time quantum : "<<quantum<<endl;
	
    findavgTime(processes, n, burst_time, quantum);
    return 0;
}
