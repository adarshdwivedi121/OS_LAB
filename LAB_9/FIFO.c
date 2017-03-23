#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];  //Sample String
    int n;          //No of Page Slots
    int *s, c=0;    //Slots & its Current Index
    int pf = 0;     //No of Page Faults
    int i, j;

    printf("\nEnter Sample Page String\n");scanf("%[^\n]%*c", str);
    printf("Enter No of Page Slots : ");scanf("%d", &n);
    s = (int *)malloc(n * sizeof(int));
    for(i=0; i<n; i++)
        s[i] = -1;

    int a, f;
    for(i=0; i<strlen(str); i+=3){
        a = str[i] - '0';
        f=0;
        for(j=0; j<n; j++)
            if(a == s[j]){
                f=1;
                break;
            }
        if(!f){
            pf++;
            s[c++] = a;
            c %= n;
        }
        printf("\nPage Slots Stat : ");
        for(j=0; j<n; j++)  printf("%2d ", s[j]);
    }

    printf("\nNo of Page Faults : %2d\n", pf);

    return 0;
}
