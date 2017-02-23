#include <stdio.h>
#include <unistd.h>

typedef struct{
	int pid;	//Process No
	int at;		//Arrival Time
	int bt;		//Burst Time
	int pt;		//Priority (0 by default)
	
	int ct;		//Closing Time
	int tat;	//Turn-Around Time
	int wt;		//Waiting Time
} PCB;

PCB B[10]; 
int n, opt;

void print_table(PCB B[]);
void print_gantt_chart(PCB B[]);
void fcfs();
//void sjf_pr();
void prior_no_pr();
//void round_robin();

int main(){	
	int i;
	printf("\n\n---------Choose Scheduling Algo----------");
	printf("\n1. First in First Out");
	printf("\n2. Shortest Job First [Premptive]");
	printf("\n3. Priority Scheduling [Non-Premptive]");
	printf("\n4. Round Robin\n------------------\n");
	scanf("%d", &opt);
	
	
	printf("\nEnter the No of Process : ");
	scanf("%d", &n);
	printf("\n--------------Process Details--------------");
	for (i=0; i<n; i++){
		B[i].pid = i;
		printf("\nProcess Id   : %d", B[i].pid);
		printf("\nArrival Time : "); scanf("%d", &B[i].at);
		printf("Burst Time   : "); scanf("%d", &B[i].bt);
		if (opt == 3){
			printf("Priority     : "); scanf("%d", &B[i].pt);
		}
		else	B[i].pt = 0;
	}
	
	switch(opt){
		case 1 : fcfs();
				 break;
	//	case 2 : sjf_pr();
	//			 break;
		case 3 : prior_no_pr();
				 break;
	//	case 4 : round_robin();
	//			 break;
	}
	
	return 0;
}

void fcfs(){
	int i, j, x;
	PCB f, A[10];
	for(i=0; i<n; i++)
		A[i] = B[i];
	
	for(i=0; i<n; i++){
		x=i;
		for(j=i+1; j<n; j++)
			if (B[x].at > B[j].at)
				x=j;
		f = B[x];
		B[x] = B[i];
		B[i] = f;
	}
	x=0;
	float av_tat=0.0, av_wt=0.0;
	
	x += B[0].at - 0;
	for(i=0; i<n; i++){
		x+=B[i].bt;
		B[i].ct = x;
		B[i].tat = B[i].ct - B[i].at;
		B[i].wt = B[i].tat - B[i].bt;
		av_tat += B[i].tat;
		av_wt += B[i].wt;
		A[B[i].pid].ct = B[i].ct;
		A[B[i].pid].tat = B[i].tat;
		A[B[i].pid].wt = B[i].wt;
	}
	
	print_table(A);
	print_gantt_chart(A);
	
	av_tat /= n;
	av_wt /= n;
	
	printf("\n\nAverage Turn-Around Time : %f", av_tat);
	printf("\nAverage Waiting Time     : %f", av_wt);
	
	printf("\n\n");
}

void prior_no_pr(){
	int i, j, x;
	PCB f, A[10];
	for(i=0; i<n; i++)
		A[i] = B[i];
	
	for(i=0; i<n; i++){
		x=i;
		for(j=i+1; j<n; j++)
			if (B[x].at > B[j].at && B[x].pt < B[j].pt)
				x=j;
		f = B[x];
		B[x] = B[i];
		B[i] = f;
	}
	
	print_table(B);
	
	x=0;
	float av_tat=0.0, av_wt=0.0;
	
	x += B[0].at - 0;
	for(i=0; i<n; i++){
		x+=B[i].bt;
		B[i].ct = x;
		B[i].tat = B[i].ct - B[i].at;
		B[i].wt = B[i].tat - B[i].bt;
		av_tat += B[i].tat;
		av_wt += B[i].wt;
		A[B[i].pid].ct = B[i].ct;
		A[B[i].pid].tat = B[i].tat;
		A[B[i].pid].wt = B[i].wt;
	}
	
	print_table(A);
	print_gantt_chart(A);
	
	av_tat /= n;
	av_wt /= n;
	
	printf("\n\nAverage Turn-Around Time : %f", av_tat);
	printf("\nAverage Waiting Time     : %f", av_wt);
	
	printf("\n\n");
}

void print_table(PCB B[])
{
    int i;
	
	if (opt == 3){
		puts("+-----+-------------+-----------+----------|--------------+-----------------+--------------+");
		puts("| PID | Arival Time |Burst Time | Priority | Closing Time | Turnaround Time | Waiting Time |");
		puts("+-----+-------------+-----------+----------|--------------+-----------------+--------------+");

		for(i=0; i<n; i++) {
		  	printf("| %2d  |      %2d     |     %2d    |    %2d    |      %2d      |       %2d        |       %2d     |\n"
		           , B[i].pid, B[i].at, B[i].bt, B[i].pt, B[i].ct, B[i].tat, B[i].wt );
			puts("+-----+-------------+-----------+----------+--------------+-----------------+--------------+");	
    	}
    }
	else{
		puts("+-----+-------------+-----------+--------------+-----------------+--------------+");
		puts("| PID | Arival Time |Burst Time | Closing Time | Turnaround Time | Waiting Time |");
		puts("+-----+-------------+-----------+--------------+-----------------+--------------+");

		for(i=0; i<n; i++) {
			printf("| %2d  |      %2d     |     %2d    |      %2d      |       %2d        |       %2d     |\n"
		           , B[i].pid, B[i].at, B[i].bt, B[i].ct, B[i].tat, B[i].wt );
			puts("+-----+-------------+-----------+--------------+-----------------+--------------+");
    	}
    }
}


void print_gantt_chart(PCB B[])
{
    int i, j;
    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<B[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing process id in the middle
    if (B[0].at > 0){
    	for(j=0; j<B[i].at - 4; j++) printf(" ");
    	printf("IDLE");
    }
    for(i=0; i<n; i++) {
        for(j=0; j<B[i].bt - 1; j++) printf(" ");
        printf("P%d", B[i].pid);
        for(j=0; j<B[i].bt - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<B[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // printing the time line
    if (B[0].at > 0){
    	for(j=0; j<B[i].at; j++) printf(" ");
    	printf("%d", B[0].at);
    }
    for(i=0; i<n; i++) {
        for(j=0; j<B[i].bt; j++) printf("  ");
        if(B[i].tat > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", B[i].ct);

    }
    printf("\n");

}
