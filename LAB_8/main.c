#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pid;
    int req_mem;
    int all_mem;
} proc;

int main() {
    int n, i, j;
    printf("\nEnter No. of Memory Slots : "); scanf("%d", &n);

    printf("\nEnter Slot Sizes\n");
    int *a = (int *)malloc(sizeof(int) * n);
    for(i=0; i<n; i++) {
        printf("Slot %d : ", i); scanf("%d", &a[i]);
    }

    int np;
    printf("Enter No. of Process : "); scanf("%d", &np);
    printf("Enter Memory Requirements : \n");
    proc *b = (proc *)malloc(sizeof(proc) * n);
    for(i=0; i<np; i++) {
        b[i].pid = i;
        printf("P%d : ", b[i].pid); scanf("%d", &b[i].req_mem);
        b[i].all_mem = 0;
    }

    for(i=0; i<np; i++)
        for(j=0; j<n; j++)
            if(b[i].req_mem <= a[j]){
                if(!b[i].all_mem)
                    b[i].all_mem = a[j];

                else if(b[i].all_mem > a[j])
                    b[i].all_mem = a[j];
            }

    for(i=0; i<np; i++){
        if(b[i].all_mem > 0)
            printf("\nProcess P%d was allocated Slot %d.", b[i].pid, b[i].all_mem);
        else
            printf("\nProcess P%d was Not allocated Slot.", b[i].pid);

    }

    return 0;
}