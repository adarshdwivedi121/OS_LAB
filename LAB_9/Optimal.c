#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];  //Sample String
//    char str[100] = "7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1";
    int n;          //No of Page Slots
    int *s, m=0;    //Slots & its Current Index
    int pf = 0;     //No of Page Faults
    int i, j;

    printf("\nEnter Sample Page String\n");scanf("%[^\n]%*c", str);
    printf("Enter No of Page Slots : ");scanf("%d", &n);
    s = (int *)malloc(n * sizeof(int));
    for(i=0; i<n; i++)
        s[i] = -1;

    int a, f;
    for(i=0; i<strlen(str); i+=2){
        a = str[i] - '0';
        f=0;
        for(j=0; j<n; j++)
            if(a == s[j]){
                f=1;
                break;
            }
        if(!f){
            if(i/2 >= n) {
                int *x = (int *) malloc(n * sizeof(int));

                for (j = 0; j < n; j++)
                    x[j] = -1;
                int k;
                for (j = 0; j < n; j++)
                    for (k = i; k < strlen(str); k++)
                        if (str[k] - '0' == s[j]) {
                            x[j] = k;
                            break;
                        }
                m = 0;
                for (k = 0; k < n; k++)
                    if (x[j] < x[m]) m = j;
                s[m] = a;
            }
            else    s[m++] = a;

            pf++;
        }
        printf("\nPage Slots Stat : ");
        for(j=0; j<n; j++)  printf("%2d ", s[j]);
    }

    printf("\nNo of Page Faults : %2d\n", pf);

    return 0;
}
