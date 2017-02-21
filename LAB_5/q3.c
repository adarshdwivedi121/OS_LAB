#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	int pid;
	int i, j;
	pid=fork();
	if (!pid){
		char list[argc-1][20];
		for (i=1; i<argc; i++)
			strcpy(list[i-1], argv[i]);

		char str[20];
		int num = argc-1;
		for (i=0; i<num; i++)
			for (j=i; j<num-1-i; j++){
				if(strcmp(list[j], list[j+1]) > 0){
					strcpy(str, list[j]);
					strcpy(list[j], list[j+1]);
					strcpy(list[j+1], str);
				}
			}
			
		printf("\n\nSorted String");
		for (i=0; i<num; i++)
			printf("\n%s", list[i]);
	}

	else{
		wait(); 
    	printf("\n\nGiven String");
		for (i=1; i<argc; i++)
	    	printf("\n%s", argv[i]);
    }

	printf("\n");
    return 0;
}
