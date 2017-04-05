#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, sum = 0, n;
    int d[100];
    int disk;   //loc of head
    int dloc;   //loc of disk in array
    printf("Enter Size of Queue : ");    scanf("%d", &n);
    printf("Enter the Queue\n");
    for (i = 0; i < n; i++)   scanf("%d", &d[i]);

    printf("Initial Head Position : ");  scanf("%d", &disk);
    d[n] = disk;
    n = n + 1;
    for (i = 0; i < n; i++)    // sorting disk locations
        for (j = i; j < n; j++)
            if (d[i] > d[j]) {
                int temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
            
    for (i = 0; i < n; i++)   // to find loc of disc in array
        if (disk == d[i]) {
            dloc = i;
            break;
        }

    sum = 0;
    for (i = dloc; i >= 0; i--) {
        printf("%d\t", d[i]);
        sum += abs(disk - d[i]);
        disk = d[i];
    }
    printf("0\t");
    sum += disk;
    disk=0;
    for (i = dloc + 2; i < n; i++) {
        printf("%d\t", d[i]);
        sum += abs(disk - d[i]);
        disk = d[i];
    }
    printf("\nmovement of total cylinders %d", sum);
    return 0;
}
