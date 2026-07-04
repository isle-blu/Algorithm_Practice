#include <stdio.h>
#include <string>
using namespace std;

string newExpression = "";
string num = "";
int ans = 0;

int calcMinus(int i)
{
    if (newExpression[i] == '\0')
    {
        return i;
    }

    if (newExpression[i] == ')')
    {
        ans -= stoi(num);
        num = "0";
        return i + 1;
    }

    if (newExpression[i] == '+')
    {
        ans -= stoi(num);
        num = "0";
        return calcMinus(++i);
    }
    else
    {
        num += newExpression[i];
        return calcMinus(++i);
    }
}

int calc(int i)
{
    if (newExpression[i] == '\0')
    {
        ans += stoi(num);
        return ans;
    }

    if (newExpression[i] == '+')
    {
        ans += stoi(num);
        num = "0";
        return calc(++i);
    }
    else if (newExpression[i] == '-')
    {
        ans += stoi(num);
        num = "0";
        i = calcMinus(i + 2);
        return calc(i);
    }
    else
    {
        num += newExpression[i];
        return calc(++i);
    }
}

int main()
{
    char expression[51];

    scanf("%s", expression);

    int i = 0;
    bool check = false;
    while (expression[i] != '\0')
    {
        if (expression[i] == '-')
        {
            if (check)
            {
                newExpression += ")-(";
            }
            else
            {
                check = true;
                newExpression += "-(";
            }
        }
        else
        {
            newExpression += expression[i];
        }

        i++;
    }

    if (expression[i] == '\0')
    {
        if (check)
        {
            newExpression += ")";
        }
    }

    calc(0);

    printf("%d", ans);

    return 0;
}