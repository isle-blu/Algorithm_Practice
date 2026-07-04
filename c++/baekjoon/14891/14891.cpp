#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;

deque<char> gear1(8);
deque<char> gear2(8);
deque<char> gear3(8);
deque<char> gear4(8);

void spining1(int direct, int before);
void spining2(int direct, int before);
void spining3(int direct, int before);
void spining4(int direct, int before);

void input_deq(deque<char> &gear)
{
    for (int i = 0; i < 7; i++)
    {
        scanf("%c", &gear[i]);
    }
    scanf("%c\n", &gear[7]);
}

void move(deque<char> &gear, int direct)
{
    char temp;
    if (direct == 1)
    {
        temp = gear.back();
        gear.pop_back();
        gear.push_front(temp);
    }
    else
    {
        temp = gear.front();
        gear.pop_front();
        gear.push_back(temp);
    }
}

void spining1(int direct, int before)
{
    if (before == 0 && gear1[2] != gear2[6])
    {
        spining2(-1 * direct, 1);
    }

    move(gear1, direct);
}

void spining2(int direct, int before)
{
    switch (before)
    {
    case 0:
        if (gear1[2] != gear2[6])
        {
            spining1(-1 * direct, 2);
        }
        if (gear2[2] != gear3[6])
        {
            spining3(-1 * direct, 2);
        }
        break;

    case 1:
        if (gear2[2] != gear3[6])
        {
            spining3(-1 * direct, 2);
        }
        break;

    case 3:
        if (gear1[2] != gear2[6])
        {
            spining1(-1 * direct, 2);
        }
        break;
    }

    move(gear2, direct);
}

void spining3(int direct, int before)
{
    switch (before)
    {
    case 0:
        if (gear2[2] != gear3[6])
        {
            spining2(-1 * direct, 3);
        }
        if (gear3[2] != gear4[6])
        {
            spining4(-1 * direct, 3);
        }
        break;

    case 2:
        if (gear3[2] != gear4[6])
        {
            spining4(-1 * direct, 3);
        }
        break;

    case 4:
        if (gear2[2] != gear3[6])
        {
            spining2(-1 * direct, 3);
        }
        break;
    }

    move(gear3, direct);
}

void spining4(int direct, int before)
{
    if (before == 0 && gear3[2] != gear4[6])
    {
        spining3(-1 * direct, 4);
    }

    move(gear4, direct);
}

void spin()
{
    int gear_turn, direct;
    scanf("%d %d", &gear_turn, &direct);

    switch (gear_turn)
    {
    case 1:
        spining1(direct, 0);
        break;
    case 2:
        spining2(direct, 0);
        break;
    case 3:
        spining3(direct, 0);
        break;
    case 4:
        spining4(direct, 0);
        break;
    }
}

int main()
{
    int spin_num, ans;

    input_deq(gear1);
    input_deq(gear2);
    input_deq(gear3);
    input_deq(gear4);

    scanf("%d", &spin_num);

    for (int i = 0; i < spin_num; i++)
    {
        spin();
    }

    ans = 0;
    ans += gear1[0] == '0' ? 0 : 1;
    ans += gear2[0] == '0' ? 0 : 2;
    ans += gear3[0] == '0' ? 0 : 4;
    ans += gear4[0] == '0' ? 0 : 8;

    printf("%d", ans);

    return 0;
}