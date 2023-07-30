#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#define MAX 100
int main()
{
	char a[10][10];
	int n, i;
	printf("Enter the number of strings:");
	scanf("%d",&n);
	printf("\nEnter the strings now:\n");
	for(i=0 ; i<n ; i++)
		scanf("%s",a[i]);

	/* -fork 2 children
		- have an if condition to check adn then sort using 2 different techniques
		-parent should wait until one of the child terminates
	*/
	pid_t parent=getpid();
	pid_t p1=fork();
	int j, min_idx;
	int status;
	if(p1==0)
	{	printf("\nThis is the first child process of parent with pid %d\n",getpid());
		char temp[MAX];

		// Sorting strings using bubble sort
		for (j=0; j<n-1; j++)
		{
			for (i=j+1; i<n; i++)
			{
				if (strcmp(a[j], a[i]) > 0)
				{
					strcpy(temp, a[j]);
					strcpy(a[j], a[i]);
					strcpy(a[i], temp);
				}
			}
		}
		printf("\nSorted using bubble sort");
			for(i=0 ; i<n ; i++)
				printf("%s\n",a[i]);
	}
	else
	{
		pid_t p2=fork();
		if(p2==0)
		{	printf("\nThis is the 2nd child of the parent with pid %d\n", getpid());
			char minStr[MAX];
			for (i = 0; i < n-1; i++)
			{
				// Find the minimum element in unsorted aay
				int min_idx = i;
				strcpy(minStr, a[i]);
				for (j = i + 1; j < n; j++)
				{
					// If min is greater than a[j]
					if (strcmp(minStr, a[j]) > 0)
					{
						// Make a[j] as minStr and update min_idx
						strcpy(minStr, a[j]);
						min_idx = j;
					}
				}

				// Swap the found minimum element with the first element
				if (min_idx != i)
				{
					char temp[MAX];
					strcpy(temp, a[i]); //swap item[pos] and item[i]
					strcpy(a[i], a[min_idx]);
					strcpy(a[min_idx], temp);
				}
			}
			printf("\nSorted using selection sort");
			for(i=0 ; i<n ; i++)
				printf("%s\n",a[i]);
		}
		else
		{
			wait(&status);
				printf("\nThis is the parent again! %d\n", getpid());
		}
	}
	return 0;
}


