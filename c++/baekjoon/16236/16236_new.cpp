#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int ans = 0;

struct Shark
{
    int size = 2;
    int x;
    int y;
    int stack = 0;
};

vector<vector<int>> box;
int stack = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void printBox(Shark &shark, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", box[i][j]);
        }
        printf("\n");
    }
    printf("%d %d", shark.size, ans);
    printf("\n");
}

bool bfs(Shark &shark, int n)
{
    vector<vector<int>> tmp_box(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    int fish_x = n;
    int fish_y = n;
    int fish_distance = n * n;

    q.push({shark.x, shark.y});
    tmp_box[shark.x][shark.y] = 0;
    while (!q.empty())
    {

        int nx = q.front().first;
        int ny = q.front().second;
        int distance = tmp_box[nx][ny];
        q.pop();

        if (fish_distance < distance)
        {
            break;
        }
        else if (box[nx][ny] < shark.size && box[nx][ny] != 0)
        {
            if (fish_x > nx)
            {
                fish_x = nx;
                fish_y = ny;
                fish_distance = distance;
            }
            else if (fish_x == nx && fish_y > ny)
            {
                fish_x = nx;
                fish_y = ny;
                fish_distance = distance;
            }
        }
        else if (box[nx][ny] > shark.size)
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            if (nx + dx[i] < 0 || nx + dx[i] >= n || ny + dy[i] < 0 || ny + dy[i] >= n || tmp_box[nx + dx[i]][ny + dy[i]] != -1)
            {
                continue;
            }

            q.push({nx + dx[i], ny + dy[i]});
            tmp_box[nx + dx[i]][ny + dy[i]] = distance + 1;
        }
    }

    if (fish_distance < n * n)
    {

        shark.x = fish_x;
        shark.y = fish_y;
        shark.stack++;

        box[fish_x][fish_y] = 0;

        ans += fish_distance;
        return false;
    }

    return true;
}

int main()
{
    Shark shark;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        vector<int> vec(n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &vec[j]);
            if (vec[j] == 9)
            {
                shark.x = i;
                shark.y = j;
                vec[j] = 0;
            }
        }
        box.push_back(vec);
    }

    while (true)
    {
        if (bfs(shark, n))
        {
            break;
        }
        if (shark.size == shark.stack)
        {
            shark.size++;
            shark.stack = 0;
        }
        //printBox(shark, n);
    }

    printf("%d", ans);
}