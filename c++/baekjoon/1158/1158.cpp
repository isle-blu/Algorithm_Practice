#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ans;

class Node
{
public:
    Node *next;
    int value;
};

Node *add(int value, Node *now)
{
    Node *node = new Node();
    node->value = value;
    node->next = now->next;

    return node;
}

Node *List(int size)
{
    Node *head = new Node();
    Node *now = new Node();
    head->next = now;
    now->value = 1;
    now->next = now;

    for (int i = 2; i <= size; i++)
    {
        now->next = add(i, now);
        now = now->next;
    }
    return head;
}

Node *pop(int num, Node *node)
{
    Node *point = node;

    for (int i = 0; i < num - 1; i++)
    {
        point = point->next;
    }

    ans.push_back(point->next->value);

    Node *tmp = point->next;
    point->next = point->next->next;

    delete tmp;

    return point;
}

int main()
{
    int size, num, count;
    scanf("%d %d", &size, &num);

    Node *now = List(size);

    int i = 0;
    count = size;
    if (size == 1)
    {
        ans.push_back(now->next->value);
    }
    else
    {
        while (count > 1)
        {
            now = pop(num, now);
            count--;
        }
        ans.push_back(now->next->value);
    }

    printf("<");
    for (i = 0; i < size - 1; i++)
    {
        printf("%d, ", ans[i]);
    }
    printf("%d>", ans.back());

    return 0;
}