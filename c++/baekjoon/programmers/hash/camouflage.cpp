#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;

    unordered_map<string, int> hash;

    for (int i = 0; i < clothes.size(); i++)
    {
        auto key = hash.find(clothes[i][1]);

        if (key == hash.end())
        {
            hash.insert({clothes[i][1], 2});
        }
        else
        {
            key->second++;
        }
    }

    for (auto i = hash.begin(); i != hash.end(); i++)
    {
        answer *= i->second;
    }

    return answer - 1;
}

int main()
{
}