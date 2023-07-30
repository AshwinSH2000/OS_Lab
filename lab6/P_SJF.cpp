#include<iostream>
using namespace std;
int wt[10]={0};
class que
{
	int Q[10];
	int f, r;
public:
	que()
	{
		f=r=-1;
	}
	void addq(int);
	int deq(int);
	void addwt();
	int peek()
	{
		if(r==-1)
			return 0;
		return 1;
	}
	int find_shortest_job(int bt[]);
};
int que::find_shortest_job(int bt[])
{
	if(r==-1)
	{
		cout<<"No process in the queue. Hence no shortest job available.";
		return -999;
	}
	else
	{
		int least_burst=100;
		int index;
		int flag=0;
        for(int i=f ; i<=r ; i++)
        {
			if(bt[Q[i]]<=least_burst)
			{
				least_burst=bt[Q[i]];
				index=Q[i];
				flag=1;
			}
        }
		if(flag)
			return index;
		else
		{
			cout<<"No process found. hence dont know what to return.";
			return 0;
		}
	}
}
void que::addq(int e)
{
	if(r==-1)
		f=r=0;
	else
		r++;
	Q[r]=e;
}
int que::deq(int x)
{
	if(f==-1)
	{
		cout<<"No element left in the queue. hence cannot return anything";
			return -999;
	}
	int copy_arr[10];
	int i=0, j=f;
	for(j; j<=r ; j++)
	{
		if(x!=Q[j])
			copy_arr[i++]=Q[j];
	}
	if(i==0)
		f=r=-1;
	else
	{	f=0; r=-1;
		for(int l=0 ; l<i ; l++)
		{
			Q[++r]=copy_arr[l];
		}
	}
	return x;
}

int main()
{
	int process[10];
	int bt[10];
	int at[10], timer=0;;
	int tat[10]={0};
	int ct[10];
	int copy_bt[10]={0};
	que q;
	int i, n;
	int completed[10]={0};
	int executing=0,dnd=-1;
	int cur_p=-1;
	int bt_cur_p=0;
	cout<<"How many processes:";
	cin>>n;
	for(i=0 ; i<n ; i++)
	{
		cout<<"Enter the details of process["<<i<<"] :\n";
		cout<<"\nArrival Time:";
		cin>>at[i];
		cout<<"\nBurst Time:";
		cin>>bt[i];
		copy_bt[i]=bt[i];
	}

	while(true)
	{
		for(i=0 ; i<n ; i++)
		{	if(at[i]==timer)
			{
				if(!q.peek() && cur_p==-1)	//if no process is there in the queue and no process is executing
				{
					//schedule this new process
                    cur_p=i;
				}
				else if(cur_p!=-1)	//if no process in the queue but some process is executing
				{
					if(bt[cur_p]>bt[i])
					{
						q.addq(cur_p);
						cur_p=i;
					}
					else
						q.addq(i);
				}
			}
		}
		bt[cur_p]--;
		timer++;
		if(bt[cur_p]==0)
		{
			//if burst time of current process becomes zero, then ct[cur_p]=timer;
			//find shooretest job fro the q.
			//schedule it
			q.deq(cur_p);
			ct[cur_p]=timer;
			if(q.peek())
				cur_p=q.find_shortest_job(bt);
			else
				break;
		}
	}
	for(i=0 ; i<n ; i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-copy_bt[i];
	}
	int twt=0, ttat=0;
	cout<<"\nProcess\tA.T.\tB.T.\tT.A.T.\tW.T.\tC.T.\n";
	for(i=0 ; i<n ; i++)
	{
		cout<<i<<"\t"<<at[i]<<"\t"<<copy_bt[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\t"<<ct[i]<<"\n";
		twt+=wt[i];
		ttat+=tat[i];
	}

	cout<<"\nAverage waiting time = "<<twt/(float)n;
	cout<<"\nAverage turn around time = "<<ttat/(float)n;
	return 0;
}
/*
	when a process comes, see if its burst time is less than the current process executing.
	if it has a less bt, schedule it
	else
	push it into the queue and continue executing
	when executing reduce the burst time of the process continouosly.
*/

