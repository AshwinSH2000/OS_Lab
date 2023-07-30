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
	int deq();
	void addwt();
	int peek()
	{
		if(r==-1)
			return 0;
		return 1;
	}
};
void que::addwt()
{	//increase the waiting time of whatever process thst is there in the queue by one
	int i;
	if(r==-1)
		return;
	else
		for(i=f ; f<=r ; i++)
			wt[i]++;

}
void que::addq(int e)
{
	if(r==-1)
		f=r=0;
	else
		r++;
	Q[r]=e;
}
int que::deq()
{
	if(f==-1)
		return -999;
	int e=Q[f];
	if(f==r)
		f=r=-1;
	else
		f++;
	return e;
}
int main()
{
	int process[10];
	int bt[10],i;
	int at[10], timer=0;;
	int tq, tat[10],n;
	int ct[10];
	que q;
	int completed[10]={0};
	int executing=0,dnd=0;
	cout<<"How many processes:";
	cin>>n;
	for(i=0 ; i<n ; i++)
	{
		cout<<"Enter the details of process["<<i<<"] :\n";
		cout<<"\nArrival Time:";
		cin>>at[i];
		cout<<"\nBurst Time:";
		cin>>bt[i];
	}
	int copy_bt[10];
	for(i=0 ; i<n ; i++)
		copy_bt[i]=bt[i];
	cout<<"Enter the time quantum:";
	cin>>tq;

	while(true)
	{
		for(i=0 ; i<n ; i++)
		{
			if(timer==at[i])
				q.addq(i);
			//q.addwt(); this is the wrong place for addwt
		}
		if(timer<dnd)
		{
			timer++;
			bt[executing]--;
			continue;
		}
		if(timer==dnd && timer!=0  && completed[executing]==0)
		{
			q.addq(executing);
		}
		if(q.peek())
		{
			executing=q.deq();
			if(bt[executing]>tq)
				dnd=timer + tq;
			else
			{
				dnd=timer+bt[executing];
				completed[executing]=1;
				ct[executing]=dnd;
			}
			bt[executing]--;
		}else
			break;
		timer++;
	}
	for(i=0 ; i<n ; i++)
	{
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-copy_bt[i];
	}
	//cout dsplaing the result
	cout<<"\nProcess\tA.T.\tB.T.\tT.A.T.\tW.T.\tC.T.\n";
	int ttat=0, twt=0;
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
/*	- at timer point of time, check which process came
			- if found, add it to the que
			- if a process is put into the queue, remove it from q aka schedule it
		*/
