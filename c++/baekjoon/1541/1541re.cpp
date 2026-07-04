#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    char expression[51];
    int ans = 0;

    scanf("%s", expression);

    int i = 0;
    bool check = false;
    string temp = "";
    while (expression[i] != '\0')
    {
        if (expression[i] == '-')
        {
            if (check)
            {
                ans -= stoi(temp);
            }
            else
            {
                check = true;
                ans += stoi(temp);
            }
            temp = "";
        }
        else if (expression[i] == '+')
        {
            if (check)
            {
                ans -= stoi(temp);
            }
            else
            {
                ans += stoi(temp);
            }
            temp = "";
        }
        else
        {
            temp += expression[i];
        }

        i++;
    }

    if (check)
    {
        ans -= stoi(temp);
    }
    else
    {
        ans += stoi(temp);
    }

    printf("%d", ans);

    return 0;
}