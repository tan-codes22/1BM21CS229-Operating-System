#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

int main()
{
    int num_processes, num_resources;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter the number of available resources:\n");
    for (int i = 0; i < num_resources; i++)
    {
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum resources required for each process:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d: ", i);
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the current allocation of resources for each process:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d: ", i);
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int safe_sequence[MAX_PROCESSES];
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES];
    int num_finished = 0;

    for (int i = 0; i < num_resources; i++)
    {
        work[i] = available[i];
    }

    while (num_finished < num_processes)
    {
        int found = 0;
        for (int i = 0; i < num_processes; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < num_resources; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }
                if (j == num_resources)
                {
                    found = 1;
                    for (int k = 0; k < num_resources; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safe_sequence[num_finished] = i;
                    finish[i] = 1;
                    num_finished++;
                }
            }
        }
        if (!found)
        {
            printf("Unsafe state detected! System cannot proceed.\n");
            return 1;
        }
    }

    printf("Safe sequence: ");
    for (int i = 0; i < num_processes; i++)
    {
        printf("%d ", safe_sequence[i]);
    }
    printf("\n");

    return 0;
}
