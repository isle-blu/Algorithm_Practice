#include <stdio.h>
#include <vector>
using namespace std;

vector<pair<int, int>> Alarm;
vector<int> count;
pair<int, int> ans;
int N, D;
int max_alarm = 0;

int fun(int num1, int num2)
{
    int tmp1 = num1;
    int tmp2 = num2;
    while (tmp1 != tmp2)
    {
        if (tmp1 < tmp2)
        {
            tmp1 += num1;
        }
        else
        {
            tmp2 += num2;
        }
    }

    return tmp1;
}

int main()
{
    scanf("%d %d", &N, &D);

    for (int i = 0; i < N; i++)
    {
        pair<int, int> tmp;
        scanf("%d %d", &tmp.first, &tmp.second);
        Alarm.push_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        count.push_back((D - Alarm[i].first) / Alarm[i].second + 1);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int sum;
            int same_min = fun(Alarm[i].second, Alarm[i].second);

            if (same_min > D - Alarm[i].first && same_min > D - Alarm[j].first)
            {
                sum = count[i] + count[j];
            }
            else
            {
                same_min = D - Alarm[i].first < D - Alarm[j].first ? D - Alarm[i].first / same_min : D - Alarm[j].first / same_min;
                sum = count[i] + count[j] - same_min - 1;
            }

            if (sum > max_alarm)
            {
                max_alarm = sum;
                ans.first = i + 1;
                ans.second = j + 1;
            }
        }
    }

    printf("%d %d\n%d", ans.first, ans.second, max_alarm);

    return 0;
}
