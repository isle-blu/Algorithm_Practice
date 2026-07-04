#include <stdio.h>
#include <unordered_set>
using namespace std;

int main()
{
    int N, num, ans;
    unordered_set<int> s;

    scanf("%d", &N);

    int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        s.insert(temp);
    }

    scanf("%d", &num);

    auto p1 = s.begin();
    temp = num - *p1;
    while (temp > *p1)
    {
        if (s.find(temp) != s.end())
        {
            ans++;
            s.erase(temp);
            p1++;
        }
        else
        {
            p1++;
        }

        temp = num - *p1;
    }

    printf("%d", ans);

    return 0;
}