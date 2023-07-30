#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,p, i, j;
	cout<<"\nHow many types of resources:";
	cin>>n;
	cout<<"\nHow many processes:";
	cin>>p;
	int allocation[10][5];
	int max[10][5];
	int available[5];
	int total[5];
	int need[10][5];
	int safestate[5],k=0;
	list <int> process;
	for(i=0 ; i<p ; i++)
		process.push_back(i);
	cout<<"What are the total number of resources of each type that the system has(total):\n";
	for(i=0 ; i<n ; i++)
	{
		cout<<"\nResource type "<<i<<" :";
		cin>>total[i];
	}
	cout<<"\nEnter the total no. of resource types for each process(max):\n";
	for(i=0 ; i<p ; i++)
	{
		for(j=0 ; j<n ; j++)
		{
			cout<<"Process "<<i<<", resource type "<<j<<" :";
			cin>>max[i][j];
		}	
	}
	cout<<"\nEnter the no. of resources allocated for each process(allocation):\n";
	for(i=0 ; i<p ; i++)
	{
		for(j=0 ; j<n ; j++)
		{
			cout<<"Process "<<i<<", resource type "<<j<<" :";
			cin>>allocation[i][j];
		}	
	}
	
	for(i=0 ; i<p ; i++)
		for(j=0 ; j<n ; j++)
		{	need[i][j]=max[i][j]-allocation[i][j]; }
            
		 
	int a[10]={0};
	//finding col sum of allocation
	for(i=0 ; i<n ; i++)
	{	
		for(j=0 ; j<p ; j++)
		{	a[i]+=allocation[j][i];	}
		available[i]=total[i]-a[i];
	}
  	 
	cout<<"Which process requests the resuource:";
	cin>>cur_p;
	int req[10];
	cout<<"What resources does it request for?\n";
	for(i=0 ; i<n ; i++)
	{
		cout<<"\nType "<<i<<" :";
		cin>>req[i];
	}
	//cur_p requests req amount of resources
	int cur_p=0, count=0;
	int completed[10]={0};
	count=0;
	for(i=0 ; i<n ; i++)
		if(req[i]<=need[cur_p][i])
			count++;		
	if(count==n)
	{	count=0;
		for(i=0 ; i<n ; i++)
			if(req[i]<=available[i])
				count++;
		if(count==n)
		{
			/*
			Available= Available – Request[i];
			Allocation[i] =Allocation[i] +Request[i];
			Need[i] =Need[i] - Request[i];
			*/
			for(i=0 ; i<n ;i++)
			{
				available[i]-=req[i];
				allocation[cur_p][i]+=request[i];
				need[cur_p][i]-=req[i];
			}
			while(true)
			{
				count=0;
				for(j=0 ; j<n ; j++)
				{
					if(need[cur_p][j]<=available[j] && completed[cur_p]==0)
						count++;
				}
				if(count==n)	//it means the resources can be allocated and the process will finish its execution
				{
					for(j=0 ; j<n ; j++)
						available[j]+=allocation[cur_p][j];
					process.remove(cur_p);	//this process is removed from process list
					safestate[k++]=cur_p;
					cout<<cur_p<<" is the current process.\n";
					completed[cur_p]=1;
				}
				cur_p=(cur_p+1)%p;
				if(process.empty())
					break;
			}
			if(k==n)		// it is a safe sequence hence it is allocated
			{	for(i=0 ; i<p ; i++)
					cout<<safestate[i]<<"\t";	
				cout<<"The requested resources are allocated";
			}
			else			//it is unsafe hance we must restore original condition
			{	for(i=0 ; i<n ;i++)
				{
					available[i]+=req[i];
					allocation[cur_p][i]-=request[i];
					need[cur_p][i]+=req[i];
				}
				cout<<"Resources are not allocated because it leads to unsafe state";
			}	
		}//fi
		else
			cout<<"\n\tThe process needs to wait as the requested resources are not available at the moment.";
	}
	else
		cout<<"Not possible to allocate these resources as it has exceeded max claim.";
	
	

	
	return 0;
}



