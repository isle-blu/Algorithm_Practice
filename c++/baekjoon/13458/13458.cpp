#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    long long ans = 0;
    int N, B, C;
    scanf("%d", &N);

    vector<int> room(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &room[i]);
    }

    scanf("%d %d", &B, &C);

    for (int i = 0; i < N; i++)
    {
        room[i] -= B;
        ans++;

        if (room[i] > 0)
        {
            ans += (room[i] / C);
            if (room[i] % C > 0)
            {
                ans++;
            }
        }
    }

    printf("%lld", ans);

    return 0;
}