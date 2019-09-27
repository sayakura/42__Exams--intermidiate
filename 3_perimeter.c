#include <stdio.h>

typedef     struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
} Node;

void    a(Node *root)
{
    if (root->left)
    {
        printf(" %d", root->value);
        a(root->left);
    }
}

void    b(Node *root)
{
    if (root->left)
        b(root->left);
    if (root->right)
        b(root->right);
    if (!root->left && !root->right)
        printf(" %d", root->value);
}

void    c(Node *root)
{
    if (root->right)
    {
        c(root->right);
        printf(" %d", root->value);
    }
}

void    perimeter(struct s_node *root)
{
    if (root)
        printf("%d", root->value);
    if (root->left)
    {
        a(root->left);
        b(root->left);
    }
    if (root->right)
    {
        b(root->right);
        c(root->right);
    }
    printf("\n");
}
