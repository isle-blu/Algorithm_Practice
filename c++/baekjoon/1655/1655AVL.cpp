#include <stdio.h>
#include <algorithm>
using namespace std;

class Node
{
public:
    int value;
    int height;
    Node *left;
    Node *right;
};

int Height(Node *node)
{
    if (node != NULL)
    {
        return node->height;
    }
    else
    {
        return -1;
    }
}

//LL
Node *singleRotateRight(Node *node)
{
    Node *temp;

    temp = node->left;
    node->left = NULL;
    temp->right = node;

    node->height = max(Height(node->right), Height(node->left)) + 1;
    temp->height = max(node->height, Height(temp->left)) + 1;

    return temp;
}

//RR
Node *singleRotateLeft(Node *node)
{
    Node *temp;

    temp = node->right;
    node->right = NULL;
    temp->left = node;

    node->height = max(Height(node->right), Height(node->left)) + 1;
    temp->height = max(node->height, Height(temp->right)) + 1;

    return temp;
}

Node *insert(int num, Node *node)
{
    if (node == NULL)
    {
        node = new Node;
        node->value = num;
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
    }
    else if (num <= node->value)
    {
        if (node->left == NULL)
        {
            node->left = insert(num, node->left);
        }
        else if (num <= node->left->value)
        {
            Node *temp = new Node;
            temp->value = num;
            temp->left = node->left;
            temp->right = NULL;
            node->left = temp;
            temp->height = Height(temp->left) + 1;
        }
        else
        {
            node->left = insert(num, node->left);
        }
    }
    else
    {
        if (node->right == NULL)
        {
            node->right = insert(num, node->right);
        }
        else if (num <= node->right->value)
        {
            Node *temp = new Node;
            temp->value = num;
            temp->right = node->right;
            temp->left = NULL;
            node->right = temp;
            temp->height = Height(temp->right) + 1;
        }
        else
        {
            node->right = insert(num, node->right);
        }
    }
    node->height = max(Height(node->left), Height(node->right)) + 1;

    return node;
}

int main()
{
    int N;
    Node *tree = new Node;

    scanf("%d", &N);

    scanf("%d", &tree->value);
    tree->height = 0;
    tree->left = NULL;
    tree->right = NULL;
    printf("%d\n", tree->value);

    int temp;
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d", &temp);
        tree = insert(temp, tree);

        if (Height(tree->left) > Height(tree->right))
        {
            tree = singleRotateRight(tree);
        }
        else if (Height(tree->right) - Height(tree->left) == 2)
        {
            tree = singleRotateLeft(tree);
        }

        printf("%d\n", tree->value);
    }

    return 0;
}