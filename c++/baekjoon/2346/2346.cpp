#include <stdio.h>
using namespace std;

class Node
{
public:
    int value;
    int index;
    Node *next;
    Node *prev;
};

Node *add(Node *head, Node *prev, int index)
{
    Node *node = new Node();
    scanf("%d", &node->value);
    node->next = head;
    node->prev = prev;
    node->index = index;

    return node;
}

int main()
{
    int N;
    scanf("%d", &N);

    Node *head = new Node();
    scanf("%d", &head->value);
    head->index = 1;

    Node *now = head;
    for (int i = 2; i <= N; i++)
    {
        now->next = new Node();
        now->next->prev = now;
        now = now->next;
        now->index = i;
        scanf("%d", &now->value);
    }
    now->next = head;
    head->prev = now;

    now = head;
    Node *tmp;
    int move;
    while (N != 0)
    {
        printf("%d ", now->index);

        tmp = now;
        now->prev->next = now->next;
        now->next->prev = now->prev;

        move = now->value;
        if (move > 0)
        {
            for (int i = 0; i < move; i++)
            {
                now = now->next;
            }
        }
        else
        {
            move *= -1;
            for (int i = 0; i < move; i++)
            {
                now = now->prev;
            }
        }

        delete tmp;
        N--;
    };

    return 0;
}