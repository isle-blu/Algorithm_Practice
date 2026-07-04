#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int N, M;
vector<vector<char>> board;
vector<pair<int, int>> start_end;
queue<pair<int, int>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int before)
{
    pair<int, int> now = q.front();
    q.pop();
    bool tf = false;

    for (int i = 0; i < 4; i++)
    {
        if (before == i)
        {
            continue;
        }

        if (now.first + dx[i] >= 0 && now.first + dx[i] < N && now.second + dy[i] >= 0 && now.second + dy[i] < N)
        {
            q.push({now.first + dx[i], now.second + dy[i]});
            tf = true;
        }
    }

    if (!tf)
    {
        board[now.first][now.second] = '@';
    }

    int main()
    {

        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; i++)
        {
            vector<char> vec(M);
            for (int j = 0; j < M; j++)
            {
                scanf("%c", vec[j]);

                if (vec[j] != '.')
                {
                    continue;
                }
                if (i == 0)
                {
                    start_end.push_back({i, j});
                }
                else if (i == N - 1)
                {
                    start_end.push_back({i, j});
                }
                else if (j == 0)
                {
                    start_end.push_back({i, j});
                }
                else if (j == M - 1)
                {
                    start_end.push_back({i, j});
                }
            }
            board.push_back(vec);
        }

        q.push(start_end[0]);

        while (!q.empty())
        {
            bfs(-1);
        }
    }