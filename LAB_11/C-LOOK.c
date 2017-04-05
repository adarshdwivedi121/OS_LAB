#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, sum = 0, n;
    int d[100];
    int disk, lim;   //loc of head
    int temp, max;
    int dloc;   //loc of disk in array
    printf("Enter Size of Queue : ");    scanf("%d", &n);
    printf("Enter the Queue\n");
    for (i = 0; i < n; i++)   scanf("%d", &d[i]);

    printf("Initial Head Position : ");  scanf("%d", &disk);
    printf("Enter Cylinder Limit : ");	scanf("%d", &lim);
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
    sum = 0;
    for (i = dloc; i >= 0; i--) {
        printf("%d\t", d[i]);
        sum += abs(disk - d[i]);
        disk = d[i];
    }
    disk=d[n-1];
    printf("%d\t", disk);
    for (i = n-2; i > dloc+1; i--) {
        printf("%d\t", d[i]);
        sum += abs(disk - d[i]);
        disk = d[i];
    }
    printf("\nmovement of total cylinders %d", sum);
    return 0;
}
