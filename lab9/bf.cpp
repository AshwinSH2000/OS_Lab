//this is best fit dynamic allocation
#include<iostream>
using namespace std;
// best fit finds the smallest hole that is large enough to fill the process
int main()
{
  int nh, np,i;
  int hole_size[10], process_size[10];
  int allocated[10], rem_size[10];
	int least=10000,smallest=-1, j;
  cout<<"Enter the number of holes available:";
  cin>>nh;
  cout<<"Enter the sizes of each of these holes:";
  for(i=0 ; i<nh ; i++)
  {
    cout<<"Hole "<<i<<": ";
    cin>>hole_size[i];
    rem_size[i]=hole_size[i];
  }
  cout<<"Enter the number of processes:";
  cin>>np;
  for(i=0 ; i<np ; i++)
    allocated[i]=-1;
  cout<<"Enter the memory requirement of each of these processes:";
  for(i=0 ; i<np ; i++)
  {
    cout<<"Process "<<i<<": ";
    cin>>process_size[i];
  }
	int updated=0;
  for(i=0 ; i<np ; i++)
  {	updated=0;
least=10000;    //have to scan through each hole. smallest fittable must be allocated
    for(j=0 ; j<nh ; j++)
    { 
      if(process_size[i]<=rem_size[j] && rem_size[j]<=least && rem_size[j]>0 )//&& allocated[j]==-1)
      {
        smallest=j;
				least=rem_size[j];
				updated=1;
      }
    }
		 if(updated){     	            //allocate this hole to the current process
    allocated[i]=smallest;   //ith process has been allocated to the jth hole
    rem_size[smallest]=rem_size[smallest]-process_size[i];}
                      //break statement will choose the next process
  }
  cout<<"\n\nprocesses:\t";
  for(i=0 ; i<np ; i++)
    cout<<i<<"\t";
  cout<<"\nalocated holes:\t";
  for(i=0 ; i<np ; i++)
    cout<<allocated[i]<<"\t";
  cout<<"\n\nAllocated hole = -1 means the process is not allocated any hole";
  cout<<"\n\nholes \t\t";
  for(i=0 ; i<nh ; i++)
    cout<<i<<"\t";  
  cout<<"\nactual sizes\t";
  for(i=0 ; i<nh ; i++)
    cout<<hole_size[i]<<"\t";
  cout<<"\nremaining \t";
  for(i=0 ; i<nh ; i++)
    cout<<rem_size[i]<<"\t";
  return 0;
}





