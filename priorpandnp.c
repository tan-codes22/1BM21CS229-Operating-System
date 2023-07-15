#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;
    int aT;
    int bT;
    int priority;
    int rT;
    int taT;
    int wT;
};

void priority_nonpreemptive(struct Process processes[], int n) {
    // Sort the processes based on priority in ascending order
    int i,j,count=0,m;
    for(i=0;i<n;i++)
    {
    if(processes[i].aT==0)
    count++;
}
if(count==n||count==1)
{
if(count==n)
{
for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

else
{
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j <= n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}
}

    int total_time = 0;
    double total_taT = 0;
    double total_wT = 0;

    for (i = 0; i < n; i++) {
        total_time += processes[i].bT;
        processes[i].taT = total_time - processes[i].aT;
        processes[i].wT = processes[i].taT - processes[i].bT;

        total_taT += processes[i].taT;
        total_wT += processes[i].wT;
    }

    printf("Process\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].taT, processes[i].wT);
    }

    printf("Average Turnaround Time: %.2f\n", total_taT / n);
    printf("Average Waiting Time: %.2f\n", total_wT / n);
}

void priority_preemptive(struct Process processes[], int n) {
    int total_time = 0,i;
    int completed = 0;

    while (completed < n) {
        int highest_priority = -1;
        int next_process = -1;

        for (i = 0; i < n; i++) {
            if (processes[i].aT <= total_time && processes[i].rT > 0) {
                if (highest_priority == -1 || processes[i].priority < highest_priority) {
                    highest_priority = processes[i].priority;
                    next_process = i;
                }
            }
        }

        if (next_process == -1) {
            total_time++;
            continue;
        }

        processes[next_process].rT--;
        total_time++;

        if (processes[next_process].rT == 0) {
            completed++;
            processes[next_process].taT = total_time - processes[next_process].aT;
            processes[next_process].wT = processes[next_process].taT - processes[next_process].bT;
        }
    }

    double total_taT = 0;
    double total_wT = 0;

    printf("Process\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].taT, processes[i].wT);

        total_taT += processes[i].taT;
        total_wT += processes[i].wT;
    }

    printf("Average Turnaround Time: %.2f\n", total_taT / n);
    printf("Average Waiting Time: %.2f\n", total_wT / n);
}

int main() {
    int n, quantum,i,choice;
    struct Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].aT);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].bT);
        printf("Enter priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].rT = processes[i].bT;
        processes[i].taT = 0;
        processes[i].wT = 0;
    }
    printf("\nSelect a scheduling algorithm:\n");
    printf("1. Priority Non-preemptive\n");
    printf("2. Priority Preemptive\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nPriority Non-preemptive Scheduling:\n");
            priority_nonpreemptive(processes, n);
            break;
        case 2:
            printf("\nPriority Preemptive Scheduling:\n");
            priority_preemptive(processes, n);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}
