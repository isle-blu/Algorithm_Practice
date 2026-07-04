#include <stdio.h>
#include <vector>
using namespace std;

int N;
vector<int> E;
vector<int> C;
int ans = 0;

void drink(int S, vector<bool> &TF, int count, int time)
{
    if (count == N)
    {
        if (ans < time)
        {
            ans = time;
        }
    }
    else if ()
    {
    }

    for (int i = 0; i < N; i++)
    {
        if (TF[i])
        {
            continue;
        }
        else
        {
            if (E[i] - S > 0)
            {
                TF[i] = true;
                drink(S + C[i], TF);
                TF[i] = false;
            }
        }
    }
}

int main()
{
    scanf("%d", &N);

    E.resize(N);
    C.resize(N);

    for (int i = 0; i < N; i++)
    {
        scanf("&d", &E[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("&d", &C[i]);
    }
}