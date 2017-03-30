#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int head,seek=0,n,i,j,temp;

	printf("\n*** FCFS Disk Scheduling Algorithm ***\n");
	printf("\nEnter the size of Queue : ");  scanf("%d",&n);
	int *queue = (int *) calloc(n, sizeof(int));
	printf("Enter the Queue\n");
	for(i=0;i<n;i++)
		      scanf("%d",&queue[i]);
	printf("Initial Head Position : ");  scanf("%d",&head);
	
	queue[0]=head;
	
	printf("Movements : ");
	for(j=0;j<=n-1;j++){
		int diff=abs(queue[j+1]-queue[j]);
		seek+=diff;
		printf("%3d\t",queue[j]);
	}
	printf("\nTotal Head Movement : %d\n",seek);
	
	return 0;
}
