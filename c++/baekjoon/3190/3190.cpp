#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

int main()
{
    int N, K, L;
    vector<vector<int>> board;
    unordered_map<int, char> turn;

    scanf("%d", &N);

    for (int i = 0; i < N + 1; i++)
    {
        vector<int> vec(N + 1);
        board.push_back(vec);
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        int x, y;

        scanf("%d %d", &x, &y);
        board[x][y] = -1;
    }

    scanf("%d", &L);
    for (int i = 0; i < L; i++)
    {
        int X;
        char C;

        scanf("%d %c", &X, &C);
        turn.insert({X, C});
    }

    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    int direction = 0; //0 = {0, 1} right / 1 = {1, 0} down / 2 = {0, -1} left / 3 = {-1, 0} up
    int ans = 0;

    while (true)
    {
        ans++;

        switch (direction)
        {
        case 0:
            snake.push_front({snake[0].first, snake[0].second + 1});
            break;
        case 1:
            snake.push_front({snake[0].first + 1, snake[0].second});
            break;
        case 2:
            snake.push_front({snake[0].first, snake[0].second - 1});
            break;
        case 3:
            snake.push_front({snake[0].first - 1, snake[0].second});
            break;
        }

        if (snake[0].first > N || snake[0].first == 0 || snake[0].second > N || snake[0].second == 0)
        {
            break;
        }
        else if (board[snake[0].first][snake[0].second] == 1)
        {
            break;
        }
        else if (board[snake[0].first][snake[0].second] == -1)
        {
            board[snake[0].first][snake[0].second] = 1;
        }
        else
        {
            board[snake[0].first][snake[0].second] = 1;
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }

        auto checkTurn = turn.find(ans);
        if (checkTurn != turn.end())
        {
            if (checkTurn->second == 'L')
            {
                switch (direction)
                {
                case 0:
                    direction = 3;
                    break;
                case 1:
                    direction = 0;
                    break;
                case 2:
                    direction = 1;
                    break;
                case 3:
                    direction = 2;
                    break;
                }
            }
            else
            {
                switch (direction)
                {
                case 0:
                    direction = 1;
                    break;
                case 1:
                    direction = 2;
                    break;
                case 2:
                    direction = 3;
                    break;
                case 3:
                    direction = 0;
                    break;
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}