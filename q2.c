#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	char str[10][10];
	printf("how many strings:");
	int n,i,j;
	scanf("%d",&n);
	char temp[10];
	printf("\nenter the strings now");
	for ( i=0 ; i<n ; i++)
		scanf("%s",str[i]);
	//input done
	pid_t p=fork();
	if(p>0)
	{	
		printf("unsorted strings displayed by parent process");
		for( i=0 ; i<n ; i++)
			printf("%s\n",str[i]);
	}
	else if(p==0)
	{
		for(i=0 ; i<n-1	 ; i++)
		{
			for(j=i+1 ; j<n-1-i ; j++)
			{
				if(strcmp(str[i],str[j])>0)
				{
					strcpy(temp,str[i]);
					strcpy(str[i],str[j]);
					strcpy(str[j],temp);
				}
			}
		}
		printf("sorted strings displayed by child process");
		for(i=0 ; i<n ; i++)
			printf("%s\n",str[i]);
	}
	return 0;
}

