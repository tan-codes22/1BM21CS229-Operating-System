#include <stdio.h>

struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
};

void srtfScheduling(struct Process processes[], int n) {
    int currentTime = 0;
    int completed = 0;

    while (completed != n) {
        int shortestIndex = -1;
        int shortestTime = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime < shortestTime && processes[i].remainingTime > 0) {
                shortestTime = processes[i].remainingTime;
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1) {
            currentTime++;
            continue;
        }

        struct Process *p = &processes[shortestIndex];
        p->remainingTime--;

        if (p->remainingTime == 0) {
            completed++;
            int turnaroundTime = currentTime - p->arrivalTime + 1;
            p->waitingTime = turnaroundTime - p->burstTime;

            printf("Process %d:\n", p->processID);
            printf("Turnaround Time: %d\n", turnaroundTime);
            printf("Waiting Time: %d\n\n", p->waitingTime);
        }

        currentTime++;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].processID = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
    }

    printf("\n--- SRTF CPU Scheduling ---\n\n");
    srtfScheduling(processes, n);

    return 0;
}
