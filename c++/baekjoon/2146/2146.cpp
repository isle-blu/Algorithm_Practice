#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N; // <= 100
int shortest = 10000;
vector<vector<int>> country(100, vector<int>(100));
vector<vector<bool>> visited(100, vector<bool>(100, false));

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check_boundary(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= N)
    {
        return false;
    }

    return true;
}

void find_island(int row, int column, int island_num)
{
    queue<pair<int, int>> bfs_q;

    bfs_q.push({row, column});
    while (!bfs_q.empty())
    {
        int x = bfs_q.front().first;
        int y = bfs_q.front().second;
        bfs_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check_boundary(nx, ny) && !visited[nx][ny] && country[nx][ny] == 1)
            {
                bfs_q.push({nx, ny});
                visited[nx][ny] = true;
                country[nx][ny] = island_num;
            }
        }
    }
}

void find_bridge(int row, int column)
{
    vector<vector<bool>> tmp_visited(100, vector<bool>(100, false));
    queue<pair<int, int>> bfs_q;
    queue<int> distance_q;
    int island_num = country[row][column];

    bfs_q.push({row, column});
    distance_q.push(0);
    while (!bfs_q.empty())
    {
        int x = bfs_q.front().first;
        int y = bfs_q.front().second;
        int distance = distance_q.front();
        bfs_q.pop();
        distance_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check_boundary(nx, ny) && !tmp_visited[nx][ny] && country[nx][ny] != island_num)
            {
                if (country[nx][ny] == 0)
                {
                    bfs_q.push({nx, ny});
                    distance_q.push(distance + 1);
                    tmp_visited[nx][ny] = true;
                }
                else if (country[nx][ny] > island_num)
                {
                    if (distance < shortest)
                    {
                        shortest = distance;
                    }
                    return;
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &country[i][j]);
        }
    }

    int island_num = 2;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && country[i][j] == 1)
            {
                country[i][j] = island_num;
                find_island(i, j, island_num);
                island_num++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (country[i][j] != 0)
            {
                find_bridge(i, j);
            }
        }
    }

    printf("%d", shortest);

    return 0;
}