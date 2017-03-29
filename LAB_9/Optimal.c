#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int val;        //Page in Slot
    int ins_time;   //Time of Insertion of the Page
}Slots;

int main() {
    char str[100];  //Sample String
    int n;          //No of Page Slots
    Slots *s;       //Slots
    int m=0;        //Current Index
    int pf = 0;     //No of Page Faults
    int i, j;

    printf("\nEnter Sample Page String\n");scanf("%[^\n]%*c", str);
    printf("Enter No of Page Slots : ");scanf("%d", &n);
    s = (Slots *)malloc(n * sizeof(Slots));
    for(i=0; i<n; i++)
        s[i].val = s[i].ins_time = -1;

    int a, f;
    int *x = (int *) malloc(n * sizeof(int));
    for(i=0; i<strlen(str); i+=2){
        a = str[i] - '0';
        f=0;
        for(j=0; j<n; j++)
            if(a == s[j].val){
                f=1;
                break;
            }
        if(!f){
            if(i > (n-1)*2) {
                for (j = 0; j < n; j++)
                    x[j] = -1;
                int k;
                for (j = 0; j < n; j++)
                    for (k = i; k < strlen(str); k++)
                        if (str[k] - '0' == s[j].val) {
                            x[j] = k;
                            break;
                        }
                m = 0;
                for (k = 0; k < n; k++){
                    if (x[k] > x[m] && x[m] !=-1 ) m = k;
                    else if((x[k] == -1) && (s[k].ins_time < s[m].ins_time))  m=k;
                }
                s[m].val = a;
                s[m].ins_time = i;
            }
            else{
                    s[m].val = a;
                    s[m].ins_time = i;
                    m++;
            }
            pf++;
            printf("\nPage Slots Stat : ");
        for(j=0; j<n; j++)  printf("%2d ", s[j].val);
        }
    }

    printf("\nNo of Page Faults : %2d\n", pf);
	
	free(s);	free(x);
    return 0;
}
