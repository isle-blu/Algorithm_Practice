#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<pair<int, string>> vec(N);
    int age;
    char name[101];

    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &age, name);
        vec[i] = {age, name};
    }

    sort(vec.begin(), vec.end(), cmp);

    for (pair<int, string> i : vec)
    {
        printf("%d %s\n", i.first, i.second.c_str());
    }
}