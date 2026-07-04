#include <stdio.h>
#include <string>
#include <map>
using namespace std;

bool compare(string answer, map<string, int> &number)
{

    if (answer[0] == answer[1] || answer[0] == answer[2] || answer[1] == answer[2])
    {
        return false;
    }
    else if (answer[1] == '0' || answer[2] == '0')
    {
        return false;
    }

    for (auto i = number.begin(); i != number.end(); i++)
    {
        int strike = 0;
        int ball = 0;
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
    char answer[4];
    map<string, int> number;

    scanf("%d", &N);

    int strike, ball;
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d", &answer, &strike, &ball);

        number.insert({answer, strike * 10 + ball});
    }

    count = 0;
    for (int i = 111; i <= 999; i++)
    {
        if (compare(to_string(i), number))
        {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}