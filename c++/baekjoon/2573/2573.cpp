#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> ice(301, vector<int>(301));
vector<vector<bool>> visited(301, vector<bool>(301, false));
vector<vector<int>> melt(301, vector<int>(301));

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int row, column;

void init()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            visited[i][j] = false;
            melt[i][j] = 0;
        }
    }
}

bool check_bfs(int nx, int ny)
{
    if (nx < 1 || nx >= row || ny < 1 || ny >= column)
    {
        return false;
    }
    return true;
}

void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int melt_cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check_bfs(nx, ny) && ice[nx][ny] > 0)
            {
                if (!visited[nx][ny])
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            else
            {
                melt_cnt++;
            }
        }

        melt[x][y] = ice[x][y] - melt_cnt;
    }
}

int year()
{
    int year_cnt = 0;

    while (true)
    {

        int ice_cnt = 0;

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < column; j++)
            {
                if (ice[i][j] > 0 && !visited[i][j])
                {
                    bfs(i, j);
                    ice_cnt++;
                }
            }
        }

        if (ice_cnt >= 2)
        {
            break;
        }
        else if (ice_cnt == 0)
        {
            year_cnt = 0;
            break;
        }

        ice = melt;
        year_cnt++;
        init();
    }

    return year_cnt;
}

int main()
{
    scanf("%d %d", &row, &column);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &ice[i][j]);
        }
    }

    printf("%d", year());

    return 0;
}
