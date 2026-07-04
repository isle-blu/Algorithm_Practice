#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, num, p1, p2, ans;
    vector<int> vec;

    scanf("%d", &N);

    int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        vec.push_back(temp);
    }

    scanf("%d", &num);

    sort(vec.begin(), vec.end());

    p1 = 0;
    p2 = N - 1;
    ans = 0;
    while (p1 < p2)
    {
        int temp = vec[p1] + vec[p2];
        if (temp == num)
        {
            ans++;
            p1++;
            p2--;
        }
        else if (temp > num)
        {
            p2--;
        }
        else
        {
            p1++;
            p2 = (p2 == N - 1) ? p2 : p2++;
        }
    }

    printf("%d", ans);

    return 0;
}
