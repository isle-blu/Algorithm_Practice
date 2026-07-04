#include <stdio.h>
#include <vector>
using namespace std;

vector<int> k;
vector<int> lotto(6);

void printCase(int count, int before, int size)
{
    if (count == 6)
    {
        for (int i = 0; i <= 5; i++)
        {
            printf("%d ", lotto[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= (size - 5) && (before + i) < size; i++)
        {
            lotto[count] = k[before + i];
            printCase(count + 1, before + i, size);
        }
    }
}

int main()
{
    int N, temp;

    lotto[0] = 0;

    while (true)
    {
        scanf("%d", &N);

        if (N == 0)
        {
            break;
        }

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &temp);
            k.push_back(temp);
        }

        printCase(0, -1, N);
        printf("\n");
        k.clear();
    }

    return 0;
}