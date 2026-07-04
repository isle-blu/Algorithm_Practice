#include <stdio.h>
#include <vector>
using namespace std;

int ans = 1;

int d; // 0: 북 , 1: 동, 2: 남, 3: 서
int x, y;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void printRoom(vector<vector<int>> &room, int n, int m)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", room[i][j]);
        }
        printf("\n");
    }
}

bool clean(vector<vector<int>> &room, int &check)
{
    int nd, nx, ny;

    room[x][y] = 2;

    if (check == 4)
    {
        nd = (d + 2) % 4;
        nx = x + dx[nd];
        ny = y + dy[nd];

        if (room[nx][ny] == 1)
        {
            return true;
        }
        else
        {
            x = nx;
            y = ny;
            check = 0;
        }
    }
    else
    {
        int nd = (d + 3) % 4;
        int nx = x + dx[nd];
        int ny = y + dy[nd];

        if (room[nx][ny] == 0)
        {
            d = nd;
            x = nx;
            y = ny;
            room[nx][ny] == 2;
            check = 0;

            ans++;
        }
        else
        {
            d = nd;
            check++;
        }
    }

    return false;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &y, &d);

    vector<vector<int>> room(n, vector<int>(m)); // 0: 칸 ,1: 벽 2: 청소O

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            room[i][j] = tmp;
        }
    }

    int check = 0;

    while (true)
    {
        if (clean(room, check))
        {
            break;
        }
        //printRoom(room, n, m);
    }

    printf("%d", ans);
}