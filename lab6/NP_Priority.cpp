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
	int find_high_prio(int prio[]);
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
int que::find_high_prio(int prio[])
{
	int priority=10;
	int index;
	int flag=0;
	for(int i=f ; i<=r ; i++)
	{
		if(prio[Q[i]]<=priority)
		{
			priority=prio[Q[i]];
			index=Q[i];
			flag=1;
		}
	}
	if(flag)
		return index;
	else
	{
		cout<<"No process found. therefore dont know what to return.";
		return 0;
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
		cout<<"No element left in the queue;";
			return -999;
	}
	int copy_arr[10];
	int i=0, j=f;
	for(j; j<=r ; j++)
	{
		if(x!=Q[j])
			copy_arr[i++]=Q[j];
	}
	//copying copy_arr back into queue;

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
	/*int e=Q[f];
	if(f==r)
		f=r=-1;
	else
		f++;
	return e;*/
}

int main()
{
	int process[10];
	int bt[10], prio[10];
	int at[10], timer=0;;
	int tat[10]={0};
	int ct[10];
	que q;
	int i, n;
	int completed[10]={0};
	int executing=0,dnd=-1;
	int cur_p;
	cout<<"How many processes:";
	cin>>n;
	for(i=0 ; i<n ; i++)
	{
		cout<<"Enter the details of process["<<i<<"] :\n";
		cout<<"\nArrival Time:";
		cin>>at[i];
		cout<<"\nBurst Time:";
		cin>>bt[i];
		cout<<"\nPriority:";
		cin>>prio[i];
	}
	int tot=0;
	for(i=0 ; i<n ; i++)
		tot+=bt[i];
	while(true)
	{
		for(i=0 ; i<n ; i++)
			if(at[i]==timer)
				q.addq(i);
				//which ever process comes, i am putting it into the queue
		if(timer<dnd)
		{
			timer++;
			continue;
		}
		if(timer==dnd)
		{
			executing=0;
		}
		if(!executing)
		{
			if(!q.peek())
				break;
			cur_p=q.find_high_prio(prio);
			q.deq(cur_p);
			dnd=timer+bt[cur_p];
			executing=1;
			ct[cur_p]=dnd;
			//have to delete the process from the queue
		}
		if(tot==timer)
			break;

		timer++;
	}
	for(i=0 ; i<n ; i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	cout<<"Process\tB.T.\tA.T.\tW.T.\tC.T.\tT.A.T\n";
	int ttat=0, twt=0;
	for(i=0 ; i<n ; i++)
	{
		cout<<i<<"\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\n";
		twt+=wt[i];
		ttat+=tat[i];
	}
	cout<<"\nAverage waiting time = "<<twt/(float)n;
	cout<<"\nAverage turn around time = "<<ttat/(float)n;
	return 0;
}

/*



*/
