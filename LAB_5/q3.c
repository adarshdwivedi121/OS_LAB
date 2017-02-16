#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	int pid;
	pid=fork();
	
	int num = argc-1, i, j;
	if (!pid){
		for (i=0; i<num; i++)
			for (j=0; j<num-1-i; j++)
				if(strcmp(argv[j], argv[j+1]) > 0){
					char *str;
					strcpy(str, argv[j]);
					strcpy(argv[j], argv[j+1]);
					strcpy(argv[j+1], str);
				}
		
		printf("\nSorted String");
		for (i=0; i<num; i++)
			printf("\n%s", argv[i]);
		printf("\n");
	}
	
	{
    	wait();
    	int i;
	printf("\nGiven String");
	for (i=0; i<num; i++)
        	printf("\n%s", argv[i]);
	printf("\n");
    }
               
    return 0;
}
