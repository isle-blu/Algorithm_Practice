#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int answer = 51;

void dfs(string begin, string target, vector<string> words, int arrSize, int wordSize, int ans)
{
    if (begin == target)
    {
        if (ans < answer)
        {
            answer = ans;
        }
        return;
    }
    else if (ans == arrSize)
    {
        return;
    }

    for (int i = 0; i < arrSize; i++)
    {
        if (words[i] == "")
        {
            continue;
        }

        bool TF = false;
        string temp = words[i];
        for (int j = 0; j < wordSize; j++)
        {
            if (words[i][j] != begin[j])
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
            words[i] = "";
            dfs(temp, target, words, arrSize, wordSize, ans + 1);
            words[i] = temp;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    dfs(begin, target, words, words.size(), words[0].size(), 0);
    if (answer == 51)
    {
        answer = 0;
    }
    return answer;
}

int main()
{
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    string begin = "hit";
    string target = "cog";
    printf("%d", solution(begin, target, words));
    return 0;
}