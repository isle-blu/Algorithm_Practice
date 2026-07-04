#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> left, pair<string, int> right)
{
    return left.second < right.second;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, L;
    string student;

    cin >> K >> L;
    map<string, int> enrolment;

    for (int i = 0; i < L; i++)
    {
        cin >> student;

        if (enrolment.find(student) != enrolment.end())
        {
            enrolment[student] = i;
        }
        else
        {
            enrolment.insert({student, i});
        }
    }

    vector<pair<string, int>> map_vector(enrolment.begin(), enrolment.end());
    sort(map_vector.begin(), map_vector.end(), cmp);

    int count = 0;
    auto i = map_vector.begin();
    while (count < K && i != map_vector.end())
    {
        cout << i->first << '\n';
        count++;
        i++;
    }

    return 0;
}