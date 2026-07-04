#include <stdio.h>
#include <vector>
using namespace std;

int ans = 11;

void choosing(int &count, vector<vector<int>> &board, pair<int, int> &red, pair<int, int> &blue, pair<int, int> &hole)
{
    if (blue == hole)
    {
        return;
    }
    else if (count > 10)
    {
        return;
    }
    else if (red == hole)
    {
        if (count < ans)
        {
            ans = count;
        }
        return;
    }

    if (board[red.first - 1][red.second] == '.' || board[red.first - 1][red.second] == 'O')
    {
        move(0);
        choosings(count + 1, board, red);
        move(1);
    }
    else if (board[red.first + 1][red.second] == '.' || board[red.first + 1][red.second] == 'O')
    {
        move(1);
        choosing(count + 1);
        move(0);
    }
    else if (board[red.first][red.second - 1] == '.' || board[red.first][red.second - 1] == 'O')
    {
        move(2);
        choosing(count + 1);
        move(3);
    }
    else if (board[red.first][red.second + 1] == '.' || board[red.first - ][red.second + 1] == 'O')
    {
        move(3);
        choosing(count + 1);
        move(2);
    }
    else
    {
        return;
    }
}

void move(int &direction, vector<vector<int>> &board, pair<int, int> &red, pair<int, int> &blue, pair<int, int> &hole)
{
    switch (direction)
    {
    case 0:
        while (board[red.first - 1][red.second] != '#')
        {
            if (board[red.first - 1][red.second] == '.')
            {
                board[red.first - 1][red.second] = R;
                red.first--;
                board[red.first][red.second] = '.';

                if (board[blue.first - 1][blue.second] == '.')
                {
                    board[blue.first - 1][blue.second] = B;
                    blue.first--;
                    board[blue.first][blue.second] = '.';
                }
                else if (board[red.first - 1][red.second] == 'O')
                {
                    blue.first--;
                    board[red.first][red.second] = '.';
                    break;
                }
            }
            else if (board[red.first - 1][red.second] == 'O')
            {
                red.first--;
                board[red.first][red.second] = '.';

                if ()
                {
                }
            }
            else if (board[red.first - 1][red.second] == 'B')
            {
            }
        }

        break;

    default:
        break;
    }
}

int main()
{
    int n;
    int m;
    vector<vector<int>> board;
    pair<int, int> red;
    pair<int, int> blue;
    pair<int, int> hole;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        vector<int> vec;
        char tmp;
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &tmp);
            vec.push_back(tmp);

            if (tmp == 'R')
            {
                red = {i, j};
            }
            else if (tmp == 'B')
            {
                blue = {i, j};
            }
            else if (tmp == 'O')
            {
                hole = {i, j};
            }
        }
        board.push_back(vec);
    }

    return 0;
}