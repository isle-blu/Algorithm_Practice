#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main()
{
    int N, tmp;

    scanf("%d", &N);
    scanf("%d", &tmp);

    maxHeap.push(tmp);
    printf("%d\n", tmp);

    for (int i = 2; i <= N; i++)
    {
        scanf("%d", &tmp);

        if (tmp > maxHeap.top())
        {
            minHeap.push(tmp);
        }
        else
        {
            maxHeap.push(tmp);
        }

        if (maxHeap.size() - minHeap.size() == 2)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        printf("%d\n", maxHeap.top());
    }

    return 0;
}