#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n, pos;

void main() {
    int ch;
    char g = 'y';
    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display \n6. Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');
}

void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Maximum number of nodes exceeded\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("\nInvalid location");
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;

    printf("\nThe elements after deletion are:");
    for (int i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
    printf("\n");
}

void search() {
    int e;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is at position %d\n", i);
            return;
        }
    }
    printf("Value %d is not in the list\n", e);
}

void insert() {
    int p;
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n || n >= MAX) {
        printf("\nInvalid location");
        return;
    }

    for (int i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }
    
    printf("\nEnter the element to insert: ");
    scanf("%d", &p);

    b[pos] = p;
    n++;

    printf("\nThe list after insertion:\n");
    display();
}

void display() {
    printf("\nThe elements of the list are:");
    for (int i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
    printf("\n");
}
