#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	int pid;	
	int num, i, j;
	printf("\nEnter the number of strings : ");
	scanf("%d", &num);
	printf("\nEnter the Strings\n");
	
	char list[num][20];
	char str[20];
	for (i=0; i<num; i++)
		scanf("%s", list[i]);
	
	//Bubble Sort Child Process
	pid = fork();
	if (pid==0){
		printf("\n\nBubble Sort \n");
		for (i=0; i<num; i++)
			for (j=0; j<num-1-i; j++){
				if(strcmp(list[j], list[j+1]) > 0){
					strcpy(str, list[j]);
					strcpy(list[j], list[j+1]);
					strcpy(list[j+1], str);
				}
			}
			
		for (i=0; i<num; i++)
			printf("\n%s", list[i]);
			
	}
	
	//Parent Process
	else{
		wait();
		pid = fork();
		if (pid == 0){
			//Selection Sort
			printf("\n\nSelection Sort \n");
			int x;
			for (i=0; i<num; i++){
				strcpy(str, list[i]);
				x=i; 
				for (j=i+1; j<num; j++)
					if(strcmp(str, list[j]) > 0){
						strcpy(str, list[j]);
						x=j;
					}

				strcpy(str, list[i]);
				strcpy(list[i], list[x]);
				strcpy(list[x], str);
			}
			
			for (i=0; i<num; i++)
			printf("\n%s", list[i]);
		} 
		
    	else{
    		printf("\n\nGiven String");
			for (i=0; i<num; i++)
				printf("\n%s", list[i]);
		}
    }

	printf("\n");
    return 0;
    
}
