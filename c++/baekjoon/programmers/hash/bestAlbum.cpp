#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}

bool compare2(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    vector<pair<string, int>> sorted_plays;
    unordered_map<string, int> genre_size;
    unordered_map<string, vector<pair<int, int>>> genreMap;
    int size = plays.size();

    for (int i = 0; i < size; i++)
    {
        auto iter = genre_size.find(genres[i]);
        auto iter2 = genreMap.find(genres[i]);
        if (iter != genre_size.end())
        {
            iter->second += plays[i];
            iter2->second.push_back({i, plays[i]});
        }
        else
        {
            genre_size.insert({genres[i], plays[i]});
            genreMap.insert({genres[i], {{i, plays[i]}}});
        }
    }

    for (auto genre : genre_size)
    {
        sorted_plays.push_back(genre);
    }

    sort(sorted_plays.begin(), sorted_plays.end(), compare);

    for (auto sorted_play : sorted_plays)
    {
        auto iter = genreMap.find(sorted_play.first);
        sort(iter->second.begin(), iter->second.end(), compare2);
        answer.push_back(iter->second[0].first);
        if (iter->second.size() > 1)
        {
            answer.push_back(iter->second[1].first);
        }
    }

    return answer;
}