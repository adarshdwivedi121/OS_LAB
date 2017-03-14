#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int pid;		//Process No
    int alloc[4];	//Allocated Memory
    int need[4];	//Needed Memory
    int max[4];		//Max Required Memory
    bool r;			//Process status

} PCB;

int main(){
    int n, i, j;
    PCB a[10];
    printf("\nEnter the number of Process : "); scanf("%d", &n);

    int work[4] = {0}, tot[4] = {0};
    printf("\nEnter Available Memory : "); scanf("%d %d %d %d", &work[0], &work[1], &work[2], &work[3]);
    for (i=0; i<4; i++)
    	tot[i] = work[i];

    printf("\nEnter the Process : \n");
    for (i=0; i<n; i++){
        printf("\nProcess Id : %d", i);a[i].pid = i;
        printf("\nAllocated Resource : "); scanf("%d %d %d %d", &a[i].alloc[0], &a[i].alloc[1], &a[i].alloc[2], &a[i].alloc[3]);
        printf("Max Resource : "); scanf("%d %d %d %d", &a[i].max[0], &a[i].max[1], &a[i].max[2], &a[i].max[3]);
        for(j=0; j<4; j++){
            a[i].need[j] = a[i].max[j] - a[i].alloc[j];
            if(a[i].need[j] < 0){
    	        printf("\nThis Allocation is Not Possible\n");
		        exit(0);
		    }
            tot[j] += a[i].alloc[j];
        }
        printf("Need Resource : %d %d %d %d\n", a[i].need[0], a[i].need[1], a[i].need[2], a[i].need[3]);
        a[i].r = false;
    }

    int req[4] = {0}, m = 0;
    printf("\nEnter the requesting Process : ");scanf("%d", &m);
    printf("\nEnter Memory Request : "); scanf("%d %d %d %d", &req[0], &req[1], &req[2], &req[3]);
    bool req_al = true;
    for(i=0; i<4; i++){
        if (req[i] > a[m].need[i] || req[i] > work[i])
            req_al = false;
    }
    if (req_al)
        for(i=0; i<4; i++){
            work[i] -= req[i];
            a[m].alloc[i] += req[i];
            a[m].need[i] -= req[i];
        }
    else {
        printf("\nThis Allocation is Not Possible\n");
        exit(0);
    }

    bool o, flag; int cd=0, ct=0;
    i=0;
    while(cd<5){
        i = i%n;
        o = false;
        flag = true;
        for(j=0; j<4; j++) {
            if(work[j]<a[i].need[j] || a[i].r) {
                flag = false;
            }
        }
        if (flag){
            for(j=0; j<4; j++){
                work[j] += a[i].alloc[j];
                a[i].need[j] = a[i].alloc[j] = 0;
            }
            a[i].r = true;
            cd++;
            o = true;
            printf("P%d ", a[i].pid);
        }
        if(!o)
            ct++;
        if(ct == 5)
            break;

        i++;
    }

    if(cd == 5)
        printf("is the Safe-Sequence.\nThis Allocation is Possible.\n");

    else if(ct == 5)
        printf("\nThis Allocation is Not Possible\n");

    return 0;
}
