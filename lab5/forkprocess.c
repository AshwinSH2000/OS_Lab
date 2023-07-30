#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(void)
{
	printf("\nHello World");
	int x=fork();
	printf("\npid=%d",x);
	printf("\nBye world");
	return 0;
}
