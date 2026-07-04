#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, front, num, now, count; // num : Q에서의 실제 index, now : front를 기준했을 때 index
    front = 1;
    count = 0;
    scanf("%d %d", &N, &M);

    vector<int> Q(N + 1, 0);
    vector<int>::iterator it;

    int tmp;
    for (int i = 1; i <= M; i++)
    {
        scanf("%d", &tmp);
        Q[tmp] = i;
    }

    for (int i = 1; i <= M; i++)
    {
        num = find(Q.begin(), Q.end(), i) - Q.begin();
        now = num - (front - 1);
        if (now <= 0)
        {
            now += N;
        }

        if (now > N / 2 + 1)
        {
            count += (N - now + 1);
            front = num == N ? 1 : num;

            it = Q.begin() + num;
            Q.erase(it);
            N--;
        }
        else
        {
            count += (now - 1);
            front = num == N ? 1 : num;

            it = Q.begin() + num;
            Q.erase(it);
            N--;
        }
    }

    printf("%d", count);

    return 0;
}