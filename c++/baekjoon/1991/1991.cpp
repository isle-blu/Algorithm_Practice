#include <stdio.h>
#include <vector>
using namespace std;

char tree[27];
int Node[27];

void preOrder(int node)
{
    if (tree[node] == '.')
    {
        return;
    }
    else
    {
        printf("%c", tree[node]);
        preOrder(node * 2);
        preOrder(node * 2 + 1);
    }
}

void inOrder(int node)
{
    if (tree[node] == '.')
    {
        return;
    }
    else
    {
        inOrder(node * 2);
        printf("%c", tree[node]);
        inOrder(node * 2 + 1);
    }
}

void postOrder(int node)
{
    if (tree[node] == '.')
    {
        return;
    }
    else
    {
        postOrder(node * 2);
        postOrder(node * 2 + 1);
        printf("%c", tree[node]);
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    tree[1] = 'A';
    Node[1] = 1;

    char tmp;
    int node;
    for (int i = 0; i < num; i++)
    {
        scanf(" %c", &tmp);
        node = tmp - 64;

        scanf(" %c", &tmp);
        tree[Node[node] * 2] = tmp;
        Node[tmp - 64] = Node[node] * 2;

        scanf(" %c", &tmp);
        tree[Node[node] * 2 + 1] = tmp;
        Node[tmp - 64] = Node[node] * 2 + 1;
    }

    preOrder(1);
    printf("\n");

    inOrder(1);
    printf("\n");

    postOrder(1);
    printf("\n");

    return 0;
}