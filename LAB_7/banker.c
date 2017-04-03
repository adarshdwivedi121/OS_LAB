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

int n, i, j, work[4] = {0};
PCB a[10];

void safety(){
    bool o, flag; int cd=0, ct=0;
    i=0;
    printf("\n");
    while(cd<n && ct<n){
        i = i%n;
        o = false;
        flag = true;
        for(j=0; j<4; j++)
            if(work[j]<a[i].need[j] || a[i].r)
                flag = false;

        if (flag){
            for(j=0; j<4; j++)
                work[j] += a[i].alloc[j];
            a[i].r = true;
            cd++;
            ct = 0;
            o = true;
            printf("P%d ", a[i].pid);
        }
        if(!o)   ct++;
        i++;
    }

    if(cd == n)
        printf("is the Safe-Sequence.\nThis Allocation is Possible.\n");

    else{
        printf("\nThis Allocation is Not Possible\n");
        exit(0);
    }
}

int main(){
    printf("\nEnter the number of Process : "); scanf("%d", &n);

    int tot[4] = {0}, avail[4] = {0};
    printf("\nEnter Available Memory : "); scanf("%d %d %d %d", &avail[0], &avail[1], &avail[2], &avail[3]);
    for (i=0; i<4; i++)    	tot[i] = work[i] = avail[i];

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

    safety();
    
	for (i=0; i<4; i++)     work[i] = avail[i];
    for (i=0; i<n; i++)     a[i].r = false;
    int req[4] = {0}, m = 0;
    printf("\nEnter the requesting Process : ");scanf("%d", &m);
    printf("\nEnter Memory Request : "); scanf("%d %d %d %d", &req[0], &req[1], &req[2], &req[3]);
    bool req_al = true;
    for(i=0; i<4; i++)
        if (req[i] > a[m].need[i] || req[i] > work[i])
            req_al = false;

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
    safety();

    return 0;
}
