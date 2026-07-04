#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> line;

int main()
{
    int N, count, ans;

    scanf("%d", &N);

    int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        line.push_back(temp);
    }

    sort(line.begin(), line.end());

    ans = 0;
    count = 0;

    for (int i = 0; i < N; i++)
    {
        count += line[i];
        ans += count;
    }

    printf("%d", ans);

    return 0;
}