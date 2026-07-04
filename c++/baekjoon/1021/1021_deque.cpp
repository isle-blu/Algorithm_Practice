#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, now, location, count;
    count = 0;

    scanf("%d %d", &N, &M);

    deque<int> Q(N);

    for (int i = 0; i < N; i++)
    {
        Q[i] = i + 1;
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &now);

        location = find(Q.begin(), Q.end(), now) - Q.begin();

        if (location > N / 2)
        {
            for (int j = 0; j < N - location - 1; j++)
            {
                int temp = Q.back();
                Q.pop_back();
                Q.push_front(temp);
            }
            Q.pop_back();

            count += (N - location);
            N--;
        }
        else
        {
            for (int j = 0; j < location; j++)
            {
                int temp = Q.front();
                Q.pop_front();
                Q.push_back(temp);
            }
            Q.pop_front();

            count += (location);
            N--;
        }
    }

    printf("%d", count);

    return 0;
}