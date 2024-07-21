#include <stdio.h>
#include <conio.h>

void main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

    // Clear the console screen (optional)
    // Uncomment the following block for Windows
    /*
    #ifdef _WIN32
        system("cls");
    #endif
    */
    // Uncomment the following block for Unix/Linux
    /*
    #ifdef __unix__
        system("clear");
    #endif
    */

    // Read the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Read the burst times for the processes
    printf("Enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    // Read the arrival times for the processes
    printf("Enter the arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize the Gantt chart array
    g[0] = 0;
    for (i = 0; i < n; i++) {
        g[i + 1] = g[i] + b[i];
    }

    // Calculate waiting time and turnaround time
    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        awt += w[i];
        att += t[i];
    }

    // Calculate average waiting time and average turnaround time
    awt = awt / n;
    att = att / n;

    // Print the process details
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i + 1, w[i], t[i]);
    }

    // Print the average waiting time and turnaround time
    printf("The average waiting time is %f\n", awt);
    printf("The average turnaround time is %f\n", att);

    getch();
}

