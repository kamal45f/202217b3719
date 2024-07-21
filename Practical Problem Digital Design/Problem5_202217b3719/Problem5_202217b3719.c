#include <stdio.h>
#include <stdlib.h>

#define n 5

void main() {
    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1, x = n;

    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");
    while (ch) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (rear == x)
                    printf("\nQueue is full");
                else {
                    printf("\nEnter no %d: ", j++);
                    scanf("%d", &queue[rear++]);
                }
                break;
            case 2:
                if (front == rear) {
                    printf("\nQueue is empty");
                } else {
                    printf("\nDeleted element is %d", queue[front++]);
                }
                break;
            case 3:
                if (front == rear) {
                    printf("\nQueue is empty");
                } else {
                    printf("\nQueue elements are:\n");
                    for (i = front; i < rear; i++) {
                        printf("%d\n", queue[i]);
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice: please see the options");
        }
    }
}