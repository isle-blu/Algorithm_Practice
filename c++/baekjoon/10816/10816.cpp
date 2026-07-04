#include <stdio.h>
#include <unordered_map>
using namespace std;

unordered_map<int, int> card;

int main()
{
    int N, M;
    scanf("%d", &N);

    int tmp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        if (card.find(tmp) != card.end())
        {
            card[tmp]++;
        }
        else
        {
            card[tmp] = 1;
        }
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &tmp);
        if (card.find(tmp) != card.end())
        {
            printf("%d ", card[tmp]);
        }
        else
        {
            printf("0 ");
        }
    }

    return 0;
}