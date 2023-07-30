//this is first fit dynamic allocation
#include<iostream>
using namespace std;

/*class hole
{ public:
  int nh;
  int hole_size[10];
};

class process
{ public:
  int np;
  int process_size[10];
 
};*/
int main()
{
  /*hole H;
  process p;*/
  int nh, np,i;
  int hole_size[10], process_size[10];
  int allocated[10], rem_size[10];

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
  int j;
  for(i=0 ; i<np ; i++)
  {
                          //have to scan through each hole. first fitting one must be allocated
    for(j=0 ; j<nh ; j++)
    { 
      if(process_size[i]<=rem_size[j] )//&& allocated[j]==-1)
      {
                          //allocate this hole to the current process
        allocated[i]=j;   //ith process has been allocated to the jth hole
        rem_size[j]=rem_size[j]-process_size[i];
        break;            //break statement will choose the next process
      }
    }
  }
  cout<<"\n\nprocesses:\t";
  for(i=0 ; i<np ; i++)
    cout<<i<<"\t";
  cout<<"\nprocess size:\t";
	for(i=0 ; i<np ; i++)
		cout<<process_size[i]<<"\t";
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





