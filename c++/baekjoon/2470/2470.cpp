#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int mix = 2000000001;
vector<int> ans(2);

int main()
{
    int N;

    scanf("%d", &N);

    int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    int p1 = 0;
    int p2 = N - 1;
    int min = 2000000001;
    while (p1 < p2 && mix != 0)
    {
        temp = abs(vec[p1] + vec[p2]);

        if (temp < min)
        {
            min = temp;
            p1++;
        }
        else
        {
            min = 2000000001;
            p2--;
        }

        if (min < mix)
        {
            mix = min;
            ans[0] = vec[p1];
            ans[1] = vec[p2 + 1];
        }
    }

    printf("%d %d", ans[0], ans[1]);

    return 0;
}