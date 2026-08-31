#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

// Create circular linked list
void create(int n) {
    struct Node *newNode, *temp;
    int value, i;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;

        if (last == NULL) {
            last = newNode;
            newNode->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }
}

// Display circular linked list
void display() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");
}

// Insert at beginning
void insertBeginning() {
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

// Insert at end
void insertEnd() {
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

// Delete from beginning
void deleteBeginning() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (temp == last) {
        last = NULL;
    } else {
        last->next = temp->next;
    }

    free(temp);
    printf("First node deleted.\n");
}

// Delete from end
void deleteEnd() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (temp == last) {
        free(last);
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }

        temp->next = last->next;
        free(last);
        last = temp;
    }

    printf("Last node deleted.\n");
}

// Search
void search() {
    struct Node *temp;
    int value;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    temp = last->next;

    do {
        if (temp->data == value) {
            printf("%d found in the list.\n", value);
            return;
        }

        temp = temp->next;

    } while (temp != last->next);

    printf("%d not found.\n", value);
}

int main() {
    int n, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    create(n);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Search\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;

            case 2:
                insertBeginning();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                search();
                break;

            case 7:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
