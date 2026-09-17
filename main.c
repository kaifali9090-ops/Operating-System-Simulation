#include <stdio.h>

typedef struct {
    int pid;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
} Process;

int main() {
    Process p[50], temp;
    int n, i, j, time = 0;
    float avgWaiting = 0, avgTurnaround = 0;

    printf("===== OPERATING SYSTEM SIMULATION =====\n");
    printf("Algorithm: FCFS Scheduling\n\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Invalid number of processes!\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nEnter Arrival Time for P%d: ", i + 1);
        scanf("%d", &p[i].arrival);

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].burst);
    }

    /* Sort according to Arrival Time */
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].arrival > p[j].arrival) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    /* FCFS Calculation */
    for (i = 0; i < n; i++) {

        if (time < p[i].arrival) {
            time = p[i].arrival;
        }

        p[i].waiting = time - p[i].arrival;

        time = time + p[i].burst;

        p[i].completion = time;

        p[i].turnaround =
            p[i].completion - p[i].arrival;

        avgWaiting += p[i].waiting;
        avgTurnaround += p[i].turnaround;
    }

    printf("\n===== PROCESS TABLE =====\n");

    printf("PID\tAT\tBT\tCT\tWT\tTAT\n");
    printf("----------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].completion,
               p[i].waiting,
               p[i].turnaround);
    }

    printf("\n===== GANTT CHART =====\n\n");

/* Top border */
for (i = 0; i < n; i++) {
    printf("--------");
}
printf("-\n");

/* Process names */
for (i = 0; i < n; i++) {
    printf("|  P%d  ", p[i].pid);
}
printf("|\n");

/* Bottom border */
for (i = 0; i < n; i++) {
    printf("--------");
}
printf("-\n");

/* Time values */
printf("0");

for (i = 0; i < n; i++) {
    printf("       %d", p[i].completion);
}

printf("\n");

    printf("\nAverage Waiting Time: %.2f",
           avgWaiting / n);

    printf("\nAverage Turnaround Time: %.2f",
           avgTurnaround / n);

    printf("\n\nSimulation completed successfully!\n");

    return 0;
}