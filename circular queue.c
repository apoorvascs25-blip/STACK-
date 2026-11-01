```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insertion
void insert() {
    int value;

    if((rear + 1) % MAX == front) {
        printf("Queue is Full\n");
    }
    else {
        printf("Enter element: ");
        scanf("%d", &value);

        if(front == -1) {
            front = 0;
        }

        rear = (rear + 1) % MAX;
        queue[rear] = value;

        printf("Element inserted\n");
    }
}

// Deletion
void delete() {
    if(front == -1) {
        printf("Queue is Empty\n");
    }
    else {
        printf("Deleted element: %d\n", queue[front]);

        if(front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }
}

// Display
void display() {
    int i;

    if(front == -1) {
        printf("Queue is Empty\n");
    }
    else {
        printf("Circular Queue: ");

        i = front;

        while(1) {
            printf("%d ", queue[i]);

            if(i == rear) {
                break;
            }

            i = (i + 1) % MAX;
        }
    }
}

// Main function
int main() {
    int choice;

    while(1) {
        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
```
