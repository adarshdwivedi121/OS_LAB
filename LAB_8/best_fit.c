#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pid;		//Process ID
    int req_mem;	//Memory Requirement of Process
    int all_mem;	//Size of Alloted Memory
    int sl_no;		//Slot No of Alloted Memory
} proc;

int main() {
    int n, i, j;
    printf("\nEnter No. of Memory Slots : "); scanf("%d", &n);

    printf("\nEnter Slot Sizes\n");
    int *a = (int *)malloc(sizeof(int) * n);
    int *f = (int *)malloc(sizeof(int) * n);
    for(i=0; i<n; i++) {
        printf("Slot %d : ", i); scanf("%d", &a[i]);
        f[i] = 0;
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
            if(b[i].req_mem <= a[j] && !f[j]){
                if(!b[i].all_mem) {
                    b[i].all_mem = a[j];
                    b[i].sl_no = j;
                    f[j] = 1;
                }

                else if(b[i].all_mem > a[j]) {
                    b[i].all_mem = a[j];
                    f[b[i].sl_no] = 0;
                    b[i].sl_no = j;
                    f[j] = 1;

                }
            }

    printf("\nProcess\tRequired\tAllocated\tSlot No\n");
    for(i=0; i<np; i++){
        if(b[i].all_mem > 0)
            printf("\n      %d\t      %2d\t       %2d\t     %d", b[i].pid, b[i].req_mem, b[i].all_mem, b[i].sl_no);
        else
            printf("\n      %d\t      %2d\t     %s\t  %s", b[i].pid, b[i].req_mem, "None", "None");
    }

    return 0;
}
