#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<char>> board;
pair<int, int> red = {-1, -1};
pair<int, int> blue = {-1, -1};
bool goal_red = false;
bool goal_blue = false;
int ans = 11;

void move(bool direction, pair<int, int> color, int pm)
{
    char color_name = color == red ? 'R' : 'B';
    char tmp = color_name == 'R' ? 'B' : 'R';

    if (direction)
    {
        while (board[color.first + pm][color.second] == '.')
        {
            board[color.first + pm][color.second] = color_name;
            board[color.first][color.second] = '.';
            color.first += pm;
        }

        if (board[color.first + pm][color.second] == 'O')
        {
            if (color_name == 'R')
            {
                goal_red = true;
            }
            else
            {
                goal_blue = true;
            }
        }
        else if (board[color.first + pm][color.second] == tmp)
        {
            if (color_name == 'R' && goal_blue)
            {
                goal_red = true;
            }
            else if (color_name == 'B' && goal_red)
            {
                goal_blue = true;
            }
        }
    }
    else
    {
        while (board[color.first][color.second + pm] == '.')
        {
            board[color.first][color.second + pm] = color_name;
            board[color.first][color.second] = '.';
            color.second += pm;
        }

        if (board[color.first][color.second + pm] == 'O')
        {
            if (color_name == 'R')
            {
                goal_red = true;
            }
            else
            {
                goal_blue = true;
            }
        }
        else if (board[color.first][color.second + pm] == tmp)
        {
            if (color_name == 'R' && goal_blue)
            {
                goal_red = true;
            }
            else if (color_name == 'B' && goal_red)
            {
                goal_blue = true;
            }
        }
    }

    if (color_name == 'R')
    {
        red = color;
    }
    else
    {
        blue = color;
    }
}

void reset(pair<int, int> tmp_red, pair<int, int> tmp_blue)
{
    board[red.first][red.second] = '.';
    board[tmp_red.first][tmp_red.second] = 'R';
    board[blue.first][blue.second] = '.';
    board[tmp_blue.first][tmp_blue.second] = 'B';
    red = tmp_red;
    blue = tmp_blue;
}

void choosing(int count, bool before)
{
    if (goal_blue)
    {
        goal_blue = false;
        if (goal_red)
        {
            goal_red = false;
        }
        return;
    }
    else if (goal_red)
    {
        if (count < ans)
        {
            ans = count;
        }
        goal_red = false;
        return;
    }
    else if (count >= 10)
    {
        return;
    }

    pair<int, int> tmp_red = red;
    pair<int, int> tmp_blue = blue;

    if (board[red.first - 1][red.second] != '#' || board[blue.first - 1][blue.second] != '#')
    {
        if (!before || before == NULL)
        {

            if (blue.second == red.second && blue.first < red.first)
            {
                move(true, blue, -1);
                move(true, red, -1);
                choosing(count + 1, true);
                reset(tmp_red, tmp_blue);
            }
            else
            {
                move(true, red, -1);
                move(true, blue, -1);
                choosing(count + 1, true);
                reset(tmp_red, tmp_blue);
            }
        }
    }

    if (board[red.first + 1][red.second] != '#' || board[blue.first + 1][blue.second] != '#')
    {
        if (!before || before == NULL)
        {
            if (blue.second == red.second && blue.first > red.first)
            {
                move(true, blue, 1);
                move(true, red, 1);
                choosing(count + 1, true);
                reset(tmp_red, tmp_blue);
            }
            else
            {
                move(true, red, 1);
                move(true, blue, 1);
                choosing(count + 1, true);
                reset(tmp_red, tmp_blue);
            }
        }
    }

    if (board[red.first][red.second - 1] != '#' || board[blue.first][blue.second - 1] != '#')
    {
        if (before || before == NULL)
        {

            if (blue.first == red.first && blue.second < red.second)
            {
                move(false, blue, -1);
                move(false, red, -1);
                choosing(count + 1, false);
                reset(tmp_red, tmp_blue);
            }
            else
            {
                move(false, red, -1);
                move(false, blue, -1);
                choosing(count + 1, false);
                reset(tmp_red, tmp_blue);
            }
        }
    }

    if (board[red.first][red.second + 1] != '#' || board[blue.first][blue.second + 1] != '#')
    {
        if (before || before == NULL)
        {
            if (blue.first == red.first && blue.second > red.second)
            {
                move(false, blue, 1);
                move(false, red, 1);
                choosing(count + 1, false);
                reset(tmp_red, tmp_blue);
            }
            else
            {
                move(false, red, 1);
                move(false, blue, 1);
                choosing(count + 1, false);
                reset(tmp_red, tmp_blue);
            }
        }
    }
}

int main()
{
    int n;
    int m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        vector<char> vec;
        char tmp;
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &tmp);
            if (tmp == '\n')
            {
                j--;
                continue;
            }

            vec.push_back(tmp);

            if (tmp == 'R')
            {
                red = {i, j};
            }
            else if (tmp == 'B')
            {
                blue = {i, j};
            }
        }
        board.push_back(vec);
    }

    if (blue.first == -1)
    {
        ans = -1;
    }
    else if (red.first == -1)
    {
        ans = 0;
    }
    else
    {
        choosing(0, NULL);
    }

    if (ans == 11)
    {
        ans = -1;
    }

    printf("%d", ans);

    return 0;
}