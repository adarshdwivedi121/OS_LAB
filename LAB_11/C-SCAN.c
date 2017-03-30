#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, j, sum = 0, n, lim;
    int d[100];
    int disk;   //loc of head
    int temp, max;
    int dloc;   //loc of disk in array
    printf("Enter Size of Queue : ");    scanf("%d", &n);
    printf("Enter the Queue\n");
    for (i = 0; i < n; i++)   scanf("%d", &d[i]);
	printf("Enter Cylinder Limit : ");	scanf("%d", &lim);
    printf("Initial Head Position : ");  scanf("%d", &disk);
    d[n] = disk;
    n = n + 1;
    for (i = 0; i < n; i++)    // sorting disk locations
    {
        for (j = i; j < n; j++) {
            if (d[i] > d[j]) {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    max = d[n];
    for (i = 0; i < n; i++)   // to find loc of disc in array
    {
        if (disk == d[i]) {
            dloc = i;
            break;
        }
    }
    for (i = dloc; i >= 0; i--) {
        printf("%d\t", d[i]);
	    if(i>0)    sum += d[i] - d[i-1];
	    printf("\n%d ", sum);
    }
    sum += d[i] - 0;
    printf("0\t%3d\t", lim-1);
    for (i = n-1; i > dloc + 1; i--) {
        printf("%d\t", d[i]);
	    if(i>dloc+2)    sum += d[i] - d[i-1];
	    printf("\n%d ", sum);
    }
    printf("\nmovement of total cylinders %d\n", sum);
    return 0;
}
