#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

queue<pair<string, int>> q;
unordered_set<string> s;

int bfs(string target, vector<string> &words, int arrSize, int wordSize)
{
    while (!q.empty())
    {
        string word = q.front().first;
        int length = q.front().second;
        q.pop();

        if (word == target)
        {
            return length;
        }

        for (int i = 0; i < arrSize; i++)
        {
            if (s.find(words[i]) != s.end())
            {
                continue;
            }

            bool TF = false;
            for (int j = 0; j < wordSize; j++)
            {
                if (words[i][j] != word[j])
                {
                    if (TF)
                    {
                        TF = false;
                        break;
                    }
                    else
                    {
                        TF = true;
                    }
                }
            }

            if (TF)
            {
                q.push({words[i], length + 1});
                s.insert(words[i]);
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words)
{
    q.push({begin, 0});

    int answer = bfs(target, words, words.size(), words[0].size());

    return answer;
}

int main()
{
    vector<string> words = {"hot", "dot", "dog", "lot", "log"};
    string begin = "hit";
    string target = "cog";
    printf("%d", solution(begin, target, words));
    return 0;
}