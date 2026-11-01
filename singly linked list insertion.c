```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    struct Node *newNode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        }
        else {
            temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

void insertFirst() {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;
}

void insertEnd() {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertPosition() {
    struct Node *newNode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1) {
        insertFirst();
        return;
    }

    temp = head;

    for(i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    create();

    while(1) {
        printf("\n1.Insert at First");
        printf("\n2.Insert at Position");
        printf("\n3.Insert at End");
        printf("\n4.Display");
        printf("\n5.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertFirst(); break;
            case 2: insertPosition(); break;
            case 3: insertEnd(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
```

