#include<stdio.h>
typedef struct {
    int pID,aT,bT,sT,cT,taT,wT;
} Process;

void calculateTimes(Process p[], int n) {
    int currT = 0;
    for (int i = 0; i < n; i++) {
        p[i].sT = currT; //Starting time for process=Current time
        p[i].cT = currT + p[i].bT; //Completion time=current time+burst time
        p[i].taT = p[i].cT - p[i].aT; //Turnaround time=completion time-arrival time
        p[i].wT = p[i].taT - p[i].bT; //Waiting time=turnaround time-burst time
        currT = p[i].cT;
    }
}

void displayp(Process p[], int n) {
    printf("Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pID, p[i].aT,
               p[i].bT, p[i].sT, p[i].cT,
               p[i].taT, p[i].wT);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &p[i].aT, &p[i].bT);
        p[i].pID = i + 1;
    }
    calculateTimes(p,n);
    //FCFS Sorting
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].aT > p[j + 1].aT) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    printf("\nCPU Scheduling a/c to FCFS algorithm:\n");
    displayp(p, n);

    //SJF Sorting
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].taT>p[j+1].taT)
            {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    calculateTimes(p,n);
    printf("\nCPU Scheduling a/c to SJF algorithm:\n");
    displayp(p,n);
    return 0;
}
