#include <stdio.h>
#include <unistd.h>

int main(){
	int pid;
	pid = fork();
	if (!pid){
		printf("\nRunning Child Process");
		printf("\nProcess id : %d", getpid());
		printf("\nParent id  : %d\n", getppid());
	}
	else{
		wait();
		printf("\nParent Process Running");
		printf("\nProcess id : %d", getpid());
                printf("\nParent id  : %d\n", getppid());
	}
}
