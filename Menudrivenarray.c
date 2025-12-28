#include <stdio.h>

int main()
{
    int arr[100], n, choice, pos, element, i, found = 0;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n---- MENU ----\n");
        printf("1. Traverse and display elements\n");
        printf("2. Search for an element (Linear Search)\n");
        printf("3. Insert an element at any position\n");
        printf("4. Delete an element from any position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Array elements are:\n");
            for (i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case 2:
            found = 0;
            printf("Enter element to search: ");
            scanf("%d", &element);
            for (i = 0; i < n; i++)
            {
                if (arr[i] == element)
                {
                    printf("Element %d found at position %d\n", element, i + 1);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Element not found!\n");
            break;

        case 3:
            if (n >= 100)
            {
                printf("Array is full, cannot insert more elements!\n");
                break;
            }
            printf("Enter position to insert (1 to %d): ", n + 1);
            scanf("%d", &pos);
            if (pos < 1 || pos > n + 1)
            {
                printf("Invalid position!\n");
                break;
            }
            printf("Enter element to insert: ");
            scanf("%d", &element);

            for (i = n; i >= pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = element;
            n++;

            printf("Element inserted successfully!\n");

            printf("Updated array: ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");

            break;

        case 4:
            if (n == 0)
            {
                printf("Array is empty, nothing to delete!\n");
                break;
            }
            printf("Enter position to delete (1 to %d): ", n);
            scanf("%d", &pos);

            if (pos < 1 || pos > n)
            {
                printf("Invalid position!\n");
                break;
            }

            element = arr[pos - 1];

            for (i = pos - 1; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;

            printf("Element %d deleted successfully!\n", element);

            printf("Updated array: ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");

            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);
    return 0;
}
