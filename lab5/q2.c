#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#define max 100
int main(int n, char *str[])
{
	int i,j;
	char temp[10];
	char *a;
	int status;
	//input done
	pid_t p=fork();
	if(p>0)
	{
		wait(&status);	//waiting until the child process finishes its execution
		printf("unsorted strings displayed by parent process\n");
		for( i=1 ; i<n ; i++)
			printf("%s\n",str[i]);
	}
	else if(p==0)
	{
		for(i=1 ; i<=n	 ; i++)
		{
			for(j=i+1 ; j<=n-1-i; j++)
			{
				if(strcmp(str[i],str[j])>0)
				{
					/*strcpy(temp,str[i]);
					strcpy(str[i],str[j]);
					strcpy(str[j],temp);*/
					a=str[i];
					str[i]=str[j];
					str[j]=a;

				}
			}
		}
		printf("sorted strings displayed by child process\n");
		for(i=1 ; i<n ; i++)
			printf("%s\n",str[i]);

	}
	return 0;
}

