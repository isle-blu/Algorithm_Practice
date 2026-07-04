#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

set<string> allNum;

bool compare(string answer, map<string, int> &number)
{
    int strike = 0;
    int ball = 0;

    for (auto i = number.begin(); i != number.end(); i++)
    {
        string num = i->first;

        if (num[0] == answer[0])
        {
            strike++;
        }
        if (num[1] == answer[1])
        {
            strike++;
        }
        if (num[2] == answer[2])
        {
            strike++;
        }

        if (num[0] == answer[1] || num[0] == answer[2])
        {
            ball++;
        }
        if (num[1] == answer[0] || num[1] == answer[2])
        {
            ball++;
        }
        if (num[2] == answer[0] || num[2] == answer[1])
        {
            ball++;
        }

        if (i->second != strike * 10 + ball)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int N, count;
    char num[4];
    map<string, int> number;
    scanf("%d", &N);

    for (int i = 123; i <= 987; i++)
    {
        string temp = to_string(i);
        if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2])
        {
            continue;
        }
        else
        {
            allNum.insert(temp);
        }
    }

    int tmp1, tmp2;
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d", num, &tmp1, &tmp2);

        number.insert({num, tmp1 * 10 + tmp2});
    }

    for (int i = 0; i < N; i++)
    {
        for (auto i = allNum.begin(); i != allNum.end(); i++)
        {
            if (!compare(*i, number))
            {
                allNum.erase(i);
                i++;
            }
        }
    }

    printf("%d", allNum.size());

    return 0;
}