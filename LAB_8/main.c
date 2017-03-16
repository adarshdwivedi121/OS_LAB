#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("\nEnter No. of Memory Slots : "); scanf("%d", &n);

    printf("\nEnter Slot Sizes\n");
    int *a =(int *) malloc(sizeof(int) * n);
    for(i=0; i<n; i++) {
        printf("Slot 1 : "); scanf("%d", &a[i]);
    }

    int np;
    printf("\nEnter No. of Process : "); scanf("%d", &n);


    return 0;
}