#include <stdio.h>
#include <vector>
using namespace std;

int ans = 0;

class fish
{
public:
    int num;       // shark = 0
    int direction; // 1=↑, 2=↖, 3=←, 4=↙, 5=↓, 6=↘, 7=→, 8=↗
};

vector<vector<fish>> fishes(4);
vector<pair<int, int>> fish_pt(17);

int dx[9] = {2, -1, -1, 0, 1, 1, 1, 0, -1}; // 0번째는 제외
int dy[9] = {2, 0, -1, -1, -1, 0, 1, 1, 1};

void change_direction(pair<int, int> pt)
{
    fishes[pt.first][pt.second].direction++;
    if (fishes[pt.first][pt.second].direction > 8)
    {
        fishes[pt.first][pt.second].direction = 1;
    }
}

void move(int sum)
{
    fish now, temp;
    pair<int, int> pt;

    for (int i = 1; i <= 16; i++)
    {
        pt = fish_pt[i];

        if (pt.first == -1)
        {
            continue;
        }

        now = fishes[pt.first][pt.second];

        if (pt.first + dx[now.direction] >= 4 || pt.second + dy[now.direction] >= 4 || pt.first + dx[now.direction] < 0 || pt.second + dy[now.direction] < 0)
        {
            change_direction(pt);
            i -= 1;
            continue;
        }

        temp = fishes[pt.first + dx[now.direction]][pt.second + dy[now.direction]];

        if (temp.num == 0)
        {
            change_direction(pt);
            i -= 1;
            continue;
        }

        fishes[pt.first + dx[now.direction]][pt.second + dy[now.direction]] = now;
        fishes[pt.first][pt.second] = temp;

        fish_pt[i] = fish_pt[temp.num];
        fish_pt[temp.num] = pt;
    }

    pt = fish_pt[0];
    now = fishes[pt.first][pt.second];

    vector<vector<fish>> tmp_fishes = fishes;
    int food;
    pair<int, int> move_pt = {pt.first + dx[now.direction], pt.second + dy[now.direction]};

    while (true)
    {
        if (move_pt.first >= 4 || move_pt.second >= 4 || move_pt.first < 0 || move_pt.second < 0)
        {
            if (ans < sum)
            {
                ans = sum;
            }
            break;
        }

        food = fishes[move_pt.first][move_pt.second].num;
        fish_pt[0] = move_pt;
        fish_pt[food] = {-1, -1};
        fishes[move_pt.first][move_pt.second].num = now.num;
        fishes[pt.first][pt.second] = {-1, -1};

        move(sum + food);
        fishes = tmp_fishes;
        fish_pt[0] = pt;
        fish_pt[food] = move_pt;

        move_pt.first += dx[now.direction];
        move_pt.second += dy[now.direction];
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        vector<fish> temp(4);

        for (int j = 0; j < 4; j++)
        {
            scanf("%d %d", &temp[j].num, &temp[j].direction);
            fish_pt[temp[j].num] = {i, j};
        }
        fishes[i] = temp;
    }

    fish_pt[fishes[0][0].num] = {-1, -1};
    fishes[0][0].num = 0;
    fish_pt[0] = {0, 0};

    move(0);

    printf("%d", ans);

    return 0;
}