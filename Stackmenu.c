#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int top = -1;
int stack[MAX];
int isempty()
{
    return top == -1;
}
int isfull()
{
    return top == MAX - 1;
}
void Push()
{
    int data;
    if (isfull())
    {
        printf("Stack is full, no space for insertion.\n");
    }
    else
    {
        printf("Enter data you want to insert: ");
        scanf("%d", &data);
        top++;
        stack[top] = data;
        printf("%d inserted.\n", data);
    }
}
void Pop()
{
    if (isempty())
    {
        printf("Stack is empty, nothing to pop.\n");
    }
    else
    {
        int data = stack[top];
        top--;
        printf("Popped element is: %d\n", data);
    }
}
void Peek()
{
    if (isempty())
    {
        printf("Stack is empty, no top element.\n");
    }
    else
    {
        printf("Topmost element is: %d\n", stack[top]);
    }
}
void Display()
{
    int i;
    if (isempty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n------ Stack Menu ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Display();
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}