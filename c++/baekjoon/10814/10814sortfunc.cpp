#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b)
{
    if (a.first.first == b.first.first)
    {
        return a.first.second < b.first.second;
    }

    return a.first.first < b.first.first;
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<pair<pair<int, int>, string>> vec(N);
    int count = 0;
    int age;
    char name[101];

    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &age, name);
        vec[i] = {{age, count}, name};
        count++;
    }

    sort(vec.begin(), vec.end(), cmp);

    for (pair<pair<int, int>, string> i : vec)
    {
        printf("%d %s\n", i.first.first, i.second.c_str());
    }
}