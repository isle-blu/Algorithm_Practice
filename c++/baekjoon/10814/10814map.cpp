#include <stdio.h>
#include <string>
#include <map>
using namespace std;

map<pair<int, int>, string> sorted;

int main()
{
    int N;
    scanf("%d", &N);

    int count = 0;
    int age;
    char name[101];

    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &age, name);
        sorted.insert({{age, count}, name});
        count++;
    }

    for (auto iter = sorted.begin(); iter != sorted.end(); iter++)
    {
        printf("%d %s\n", iter->first.first, (iter->second).c_str());
    }
}