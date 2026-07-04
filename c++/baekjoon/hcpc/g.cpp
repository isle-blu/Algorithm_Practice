#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    bool graph[N][N];

    for (int i = 0; i < N; i++)
    {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        graph[tmp1][tmp2] = true;
        graph[tmp2][tmp1] = true;
    }
}