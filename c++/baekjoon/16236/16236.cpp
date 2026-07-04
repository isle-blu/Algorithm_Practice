#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int ans = 0;

vector<vector<int>> box;
int stack = 0;
int n, x, y;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

/*
void printBox()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", box[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
*/

bool bfs(int &size)
{
    //    printBox();
    vector<vector<int>> tmp_box(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    int shark_x = n;
    int shark_y = n;
    int distance = n * n;

    q.push({x, y});
    tmp_box[x][y] = 0;
    while (!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        if (tmp_box[nx][ny] > distance)
        {
            break;
        }
        else if (box[nx][ny] < size && box[nx][ny] != 0)
        {
            if (shark_x > nx)
            {
                shark_x = nx;
                shark_y = ny;
                distance = tmp_box[nx][ny];
            }
            else if (shark_x == nx && shark_y > ny)
            {
                shark_x = nx;
                shark_y = ny;
                distance = tmp_box[nx][ny];
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int tmp_x = nx + dx[i];
            int tmp_y = ny + dy[i];
            if (tmp_x < 0 || tmp_x >= n || tmp_y < 0 || tmp_y >= n)
            {
                continue;
            }
            else if (box[tmp_x][tmp_y] > size || tmp_box[tmp_x][tmp_y] >= 0)
            {
                continue;
            }

            q.push({tmp_x, tmp_y});
            tmp_box[tmp_x][tmp_y] = tmp_box[nx][ny] + 1;
        }
    }

    if (distance < n * n)
    {
        stack++;
        if (stack == size)
        {
            stack = 0;
            size++;
        }

        box[x][y] = 0;
        box[shark_x][shark_y] = 9;
        x = shark_x;
        y = shark_y;

        ans += distance;
        return true;
    }

    return false;
}

int main()
{
    int size = 2;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        vector<int> vec(n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &vec[j]);
            if (vec[j] == 9)
            {
                x = i;
                y = j;
            }
        }
        box.push_back(vec);
    }

    vector<vector<int>> tmp_box(n, vector<int>(n, -1));
    while (true)
    {
        if (!bfs(size))
        {
            break;
        }
    }

    printf("%d", ans);
}