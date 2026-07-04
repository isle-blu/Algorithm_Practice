#include <stdio.h>
using namespace std;

int ans = 0;
int days;

void dfs(int count, int before)
{
    if (count == days - 1)
    {
        ans++;
        return;
    }

    switch (before)
    {
    case 1:
        dfs(count + 1, 3);
        dfs(count + 1, 4);
        dfs(count + 1, -1);
        break;

    case 2:
        dfs(count + 1, 4);
        dfs(count + 1, -1);
        break;

    case 3:
        dfs(count + 1, 1);
        dfs(count + 1, -1);
        break;

    case 4:
        dfs(count + 1, 1);
        dfs(count + 1, 2);
        dfs(count + 1, -1);
        break;

    default:
        dfs(count + 1, 1);
        dfs(count + 1, 2);
        dfs(count + 1, 3);
        dfs(count + 1, 4);
        break;
    }
}

int main()
{
    scanf("%d", &days);

    if (days > 1)
    {
        //1
        dfs(1, 3);
        dfs(1, 4);
        dfs(1, -1);

        //2
        dfs(1, 4);
        dfs(1, -1);

        //3
        dfs(1, 1);
        dfs(1, -1);

        //4
        dfs(1, 1);
        dfs(1, 2);
        dfs(1, -1);

        // -1
        dfs(1, 1);
        dfs(1, 2);
        dfs(1, 3);
        dfs(1, 4);
    }
    else
    {
        ans = 5;
    }

    printf("%d", ans % 1000000007);
}