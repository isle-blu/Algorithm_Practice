#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void compare(string str, int *count)
{
    char before;
    vector<char> vec;

    before = str[0];
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != before)
        {
            if (find(vec.begin(), vec.end(), str[i]) != vec.end())
            {
                return;
            }
            else
            {
                vec.push_back(before);
                before = str[i];
            }
        }
    }
    *count += 1;
}

int main()
{
    int num, count;
    string str;

    scanf("%d", &num);

    count = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> str;
        compare(str, &count);
    }

    printf("%d", count);

    return 0;
}