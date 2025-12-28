#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct node *findMin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int height(struct node *root)
{
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main()
{
    struct node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n===== Binary Search Tree MENU =====\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Inorder\n");
        printf("5. Preorder\n6. Postorder\n7. Height\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;

        case 3:
            printf("Enter key to search: ");
            scanf("%d", &value);
            if (search(root, value))
                printf("Key found\n");
            else
                printf("Key not found\n");
            break;

        case 4:
            inorder(root);
            break;

        case 5:
            preorder(root);
            break;

        case 6:
            postorder(root);
            break;

        case 7:
            printf("Height = %d\n", height(root));
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
