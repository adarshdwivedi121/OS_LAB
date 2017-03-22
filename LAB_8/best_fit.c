#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pid;		//Process ID
    int req_mem;	//Memory Requirement of Process
    int all_mem;	//Size of Alloted Memory
    int sl_no;		//Slot No of Alloted Memory
} proc;

typedef struct{
	int sno;
    int size;		//Size of the Slot
	int left;		//Left Memory
} hole;

int main() {
    int n, i, j;
    printf("\nEnter No. of Memory Slots : "); scanf("%d", &n);

    printf("\nEnter Slot Sizes\n");
    hole *a = (hole *)malloc(sizeof(hole) * n);
    int *f = (int *)malloc(sizeof(int) * n);
    for(i=0; i<n; i++) {
        a[i].sno = i;
        printf("Slot %d : ", i); scanf("%d", &a[i].size);
        a[i].left = a[i].size;
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

    for(i=0; i<n; i++)
        for(j=0; j<n-1; j++)
            if(a[j].size > a[j+1].size) {
                hole h = a[j];
                a[j] = a[j + 1];
                a[j + 1] = h;
            }

    for(i=0; i<np; i++)
        for(j=0; j<n; j++)
            if(b[i].req_mem <= a[j].size && !f[j]){
                if(!b[i].all_mem) {
                    b[i].all_mem = b[i].req_mem;
                    a[j].left -= b[i].req_mem;
                    b[i].sl_no = j;
                    f[j] = 1;
                }

                else if(a[j].size - b[i].req_mem < a[b[i].sl_no].left) {
                    b[i].all_mem = a[j].size;
                    f[b[i].sl_no] = 0;
                    a[j].left -= b[i].req_mem;
                    a[b[i].sl_no].left = a[b[i].sl_no].size;
                    b[i].sl_no = j;
                    f[j] = 1;

                }
            }

    printf("\n%12s\t%12s\t%12s\t%12s\t%12s\n", "Process", "Required", "Slot No", "Slot Size", "Left Memory");
    for(i=0; i<np; i++){
        if(b[i].all_mem > 0)
            printf("\n%12d\t%12d\t%12d\t%12d\t%12d", b[i].pid, b[i].req_mem, a[b[i].sl_no].sno, a[b[i].sl_no].size, a[b[i].sl_no].left);
        else
            printf("\n%12d\t%12d\t%12s\t%12s\t%12s", b[i].pid, b[i].req_mem, "None", "None", "None");
    }


    return 0;
}
