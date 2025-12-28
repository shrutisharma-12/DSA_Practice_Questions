#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createList()
{
    int n, value, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtPosition(int value, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(int value)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found.\n");
        return;
    }

    if (prev == NULL)
    {
        head = head->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    printf("Node with value %d deleted.\n", value);
}

void deleteByPosition(int position)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    if (position == 1)
    {
        head = head->next;
        free(temp);
        printf("Node at position %d deleted.\n", position);
        return;
    }

    struct Node *prev = NULL;
    int i;
    for (i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node at position %d deleted.\n", position);
}

void display()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, value, position;

    do
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete by Value\n");
        printf("6. Delete by Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createList();
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 4:
            printf("Enter value and position: ");
            scanf("%d %d", &value, &position);
            insertAtPosition(value, position);
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(value);
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteByPosition(position);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
