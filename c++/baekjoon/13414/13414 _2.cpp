#include <stdio.h>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> left, pair<string, int> right)
{
    return left.second < right.second;
}

int main()
{
    int K, L;
    char student[9];

    scanf("%d %d", &K, &L);
    unordered_map<string, int> enrolment;
    queue<pair<string, int>> q;

    int value = 0;
    for (int i = 0; i < L; i++)
    {
        scanf("%s\n", student);

        auto tmp = enrolment.find(student);
        if (tmp != enrolment.end())
        {
            enrolment.erase(tmp);
                }
        else
        {
            enrolment.insert({student, value});
        }
        value++;
    }

    vector<pair<string, int>> map_vector(enrolment.begin(), enrolment.end());
    sort(map_vector.begin(), map_vector.end(), cmp);

    for (int i = 0; i < K; i++)
    {
        printf("%s\n", map_vector[i].first);
    }

    return 0;
}