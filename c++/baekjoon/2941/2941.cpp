#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int count = 0;

    cin >> str;

    int i = 0;
    while (str[i])
    {
        if (str[i] == 'c')
        {
            if (str[i + 1] == '=' || str[i + 1] == '-')
            {
                i++;
            }
        }
        else if (str[i] == 'd')
        {
            if (str[i + 1] == '-')
            {
                i++;
            }
            else if (str[i + 1] == 'z' && str[i + 2] == '=')
            {
                i += 2;
            }
        }
        else if (str[i] == 'l' || str[i] == 'n')
        {
            if (str[i + 1] == 'j')
            {
                i++;
            }
        }
        else if (str[i] == 's' || str[i] == 'z')
        {
            if (str[i + 1] == '=')
            {
                i++;
            }
        }

        i++;
        count++;
    }

    printf("%d", count);

    return 0;
}