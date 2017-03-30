#include <stdlib.h>
#include<math.h>
void main()
{
	int head,seek=0,n,i,j,temp;

	printf("\n*** SSTF Disk Scheduling Algorithm ***\n");
	printf("\nEnter the size of Queue : ");  scanf("%d",&n);
	int *queue = (int *) calloc(n, sizeof(int));
	int *t = (int *) calloc(n, sizeof(int));
	printf("Enter the Queue\n");
	for(i=0;i<n;i++)
		      scanf("%d",&queue[i]);
	printf("Initial Head Position : ");  scanf("%d",&head);
	
     for(i=1;i<n;i++)  t[i]=abs(head-queue[i]);
     for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
           if(t[i]>t[j])
           {
	            temp=t[i];
                t[i]=t[j];
                t[j]=temp;
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
           }
           
	printf("Movements : %3d\t", head);
	for(i=1;i<n-1;i++){
		seek=seek+abs(head-queue[i]);
		head=queue[i];
		printf("%3d\t",head);
	}
	printf("\nTotal Head Movement : %d\n",seek);
}
