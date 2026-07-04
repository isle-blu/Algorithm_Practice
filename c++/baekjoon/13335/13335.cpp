#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int N, W, L;
    scanf("%d %d %d", &N, &W, &L);

    int count, weight, ans, p1, p2;
    vector<int> truck(N);
    vector<int> pass(N, W);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &truck[i]);
    }

    count = 1;
    weight = truck[0];
    ans = 1;
    p1 = 0;
    p2 = 0;

    while (p1 < N)
    {
        for (int i = p1; i <= p2; i++)
        {
            pass[i]--;
        }

        if (pass[p1] == 0)
        {
            count--;
            weight -= truck[p1];
            p1++;
        }

        if (p2 < N && count < W && weight + truck[p2 + 1] <= L)
        {
            p2++;
            count++;
            weight += truck[p2];
        }

        ans++;
    }

    printf("%d", ans);

    return 0;
}