#include <stdio.h>
#include <vector>
using namespace std;

int ans = 0;
int N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(const vector<vector<int>> board, int before, int count);
vector<vector<int>> check(vector<vector<int>> &board, int direction);
void sum_up_down(vector<vector<int>> &board, int direction, pair<int, int> cur, pair<int, int> block);
void sum_left_right(vector<vector<int>> &board, int direction, pair<int, int> cur, pair<int, int> block);
//void print_board(vector<vector<int>> board, int N);

int main()
{
    vector<vector<int>> board;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        vector<int> vec;
        int tmp;
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &tmp);
            vec.push_back(tmp);
            if (tmp > ans)
            {
                ans = tmp;
            }
        }
        board.push_back(vec);
    }
    dx[1] = N - 1;
    dy[3] = N - 1;
    if (N > 1)
    {
        dfs(board, -1, 0);
    }
    printf("%d", ans);

    return 0;
}

void dfs(const vector<vector<int>> board, int before, int count)
{
    if (count >= 5)
    {
        return;
    }

    vector<vector<int>> tmp_board = board;

    for (int i = 0; i < 4; i++)
    {
        //printf("%d %d\n", count, i);
        dfs(check(tmp_board, i), i, count + 1);
        tmp_board = board;
    }
}

vector<vector<int>> check(vector<vector<int>> &board, int direction)
{
    pair<int, int> start;
    pair<int, int> cur;
    pair<int, int> block;
    auto tmp_board = board;

    if (direction < 2)
    {
        start = {dx[direction], 0};

        for (int i = 0; i < N; i++)
        {
            cur = {start.first + dy[direction], start.second};
            block = start;
            sum_up_down(tmp_board, direction, cur, block);
            start.second++;
            //print_board(tmp_board, N);
        }
    }
    else
    {
        start = {0, dy[direction]};

        for (int i = 0; i < N; i++)
        {
            cur = {start.first, start.second + dx[direction]};
            block = start;
            sum_left_right(tmp_board, direction, cur, block);
            start.first++;
        }
    }

    return tmp_board;
}

void sum_up_down(vector<vector<int>> &board, int direction, pair<int, int> cur, pair<int, int> block)
{
    while (true)
    {
        if (board[block.first][block.second] == 0)
        {
            if (board[cur.first][cur.second] != 0)
            {
                board[block.first][block.second] = board[cur.first][cur.second];
                board[cur.first][cur.second] = 0;
            }
            cur.first += dy[direction];
        }
        else if (board[cur.first][cur.second] == board[block.first][block.second])
        {
            board[block.first][block.second] *= 2;
            board[cur.first][cur.second] = 0;

            if (board[block.first][block.second] > ans)
            {
                ans = board[block.first][block.second];
            }

            block.first += dy[direction];
            cur.first += dy[direction];
        }
        else if (board[cur.first][cur.second] != 0)
        {
            block.first += dy[direction];
            if (block == cur)
            {
                cur.first += dy[direction];
            }
        }
        else
        {
            cur.first += dy[direction];
        }

        if (cur.first < 0 || cur.first >= N)
        {
            break;
        }
    }
}

void sum_left_right(vector<vector<int>> &board, int direction, pair<int, int> cur, pair<int, int> block)
{
    while (true)
    {
        if (board[block.first][block.second] == 0)
        {
            if (board[cur.first][cur.second] != 0)
            {
                board[block.first][block.second] = board[cur.first][cur.second];
                board[cur.first][cur.second] = 0;
            }
            cur.second += dx[direction];
        }
        else if (board[cur.first][cur.second] == board[block.first][block.second])
        {
            board[block.first][block.second] *= 2;
            board[cur.first][cur.second] = 0;

            if (board[block.first][block.second] > ans)
            {
                ans = board[block.first][block.second];
            }

            block.second += dx[direction];
            cur.second += dx[direction];
        }
        else if (board[cur.first][cur.second] != 0)
        {
            block.second += dx[direction];
            if (block == cur)
            {
                cur.second += dx[direction];
            }
        }
        else
        {
            cur.second += dx[direction];
        }

        if (cur.second < 0 || cur.second >= N)
        {
            break;
        }
    }
}

/*
void print_board(vector<vector<int>> board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
*/
