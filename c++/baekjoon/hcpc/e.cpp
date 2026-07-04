#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

int main()
{
    vector<bool> star(12, false);
    map<pair<int, int>, int> participant_map;
    int N;

    for (int i = 0; i < 7; i++)
    {
        pair<int, int> tmp;
        scanf("%d %d", &tmp.first, &tmp.second);

        if (tmp.first == 1)
        {
            if (tmp.second < 20)
            {
                if (!star[11])
                {
                    star[11] = true;
                }
            }
            else if (!star[0])
            {
                star[0] = true;
            }
        }
        else if (tmp.first == 4)
        {
            if (tmp.second < 20)
            {
                if (!star[2])
                {
                    star[2] = true;
                }
            }
            else if (!star[3])
            {
                star[3] = true;
            }
        }
        else if (tmp.first == 2)
        {
            if (tmp.second < 19)
            {
                if (!star[0])
                {
                    star[0] = true;
                }
            }
            else if (!star[1])
            {
                star[1] = true;
            }
        }
        else if (tmp.first == 3 || tmp.first == 5)
        {
            if (tmp.second < 21)
            {
                if (!star[tmp.first - 2])
                {
                    star[tmp.first - 2] = true;
                }
            }
            else if (!star[tmp.first - 1])
            {
                star[tmp.first - 1] = true;
            }
        }
        else if (tmp.first == 6 || tmp.first == 12)
        {
            if (tmp.second < 22)
            {
                if (!star[tmp.first - 2])
                {
                    star[tmp.first - 2] = true;
                }
            }
            else if (!star[tmp.first - 1])
            {
                star[tmp.first - 1] = true;
            }
        }
        else if (tmp.first == 7 || tmp.first == 8 || tmp.first == 9 || tmp.first == 10 || tmp.first == 11)
        {
            if (tmp.second < 23)
            {
                if (!star[tmp.first - 2])
                {
                    star[tmp.first - 2] = true;
                }
            }
            else if (!star[tmp.first - 1])
            {
                star[tmp.first - 1] = true;
            }
        }
    }

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        pair<int, int> tmp;
        scanf("%d %d", &tmp.first, &tmp.second);

        if (tmp.first == 1)
        {
            if (tmp.second < 20)
            {
                if (!star[11])
                {
                    if (participant_map.find(tmp) != participant_map.end())
                    {
                        participant_map[tmp]++;
                    }
                    participant_map.insert({tmp, 1});
                }
            }
            else if (!star[0])
            {
                if (participant_map.find(tmp) != participant_map.end())
                {
                    participant_map[tmp]++;
                }
                participant_map.insert({tmp, 1});
            }
        }
        else if (tmp.first == 4)
        {
            if (tmp.second < 20)
            {
                if (!star[2])
                {
                    if (participant_map.find(tmp) != participant_map.end())
                    {
                        participant_map[tmp]++;
                    }
                    participant_map.insert({tmp, 1});
                }
            }
            else if (!star[3])
            {
                if (participant_map.find(tmp) != participant_map.end())
                {
                    participant_map[tmp]++;
                }
                participant_map.insert({tmp, 1});
            }
        }
        else if (tmp.first == 2)
        {
            if (tmp.second < 19)
            {
                if (!star[0])
                {
                    if (participant_map.find(tmp) != participant_map.end())
                    {
                        participant_map[tmp]++;
                    }
                    participant_map.insert({tmp, 1});
                }
            }
            else if (!star[1])
            {
                if (participant_map.find(tmp) != participant_map.end())
                {
                    participant_map[tmp]++;
                }
                participant_map.insert({tmp, 1});
            }
        }
        else if (tmp.first == 3 || tmp.first == 5)
        {
            if (tmp.second < 21)
            {
                if (!star[tmp.first - 2])
                {
                    if (participant_map.find(tmp) != participant_map.end())
                    {
                        participant_map[tmp]++;
                    }
                    participant_map.insert({tmp, 1});
                }
            }
            else if (!star[tmp.first - 1])
            {
                if (participant_map.find(tmp) != participant_map.end())
                {
                    participant_map[tmp]++;
                }
                participant_map.insert({tmp, 1});
            }
        }
        else if (tmp.first == 6 || tmp.first == 12)
        {
            if (tmp.second < 22)
            {
                if (!star[tmp.first - 2])
                {
                    if (participant_map.find(tmp) != participant_map.end())
                    {
                        participant_map[tmp]++;
                    }
                    participant_map.insert({tmp, 1});
                }
            }
            else if (!star[tmp.first - 1])
            {
                if (participant_map.find(tmp) != participant_map.end())
                {
                    participant_map[tmp]++;
                }
                participant_map.insert({tmp, 1});
            }
        }
        else if (tmp.first == 7 || tmp.first == 8 || tmp.first == 9 || tmp.first == 10 || tmp.first == 11)
        {
            if (tmp.second < 23)
            {
                if (!star[tmp.first - 2])
                {
                    if (participant_map.find(tmp) != participant_map.end())
                    {
                        participant_map[tmp]++;
                    }
                    participant_map.insert({tmp, 1});
                }
            }
            else if (!star[tmp.first - 1])
            {
                if (participant_map.find(tmp) != participant_map.end())
                {
                    participant_map[tmp]++;
                }
                participant_map.insert({tmp, 1});
            }
        }
    }

    if (!participant_map.empty())
    {
        for (auto i : participant_map)
        {
            for (int j = 0; j < i.second; j++)
            {
                printf("%d %d\n", i.first.first, i.first.second);
            }
        }
    }
    else
    {
        printf("ALL FAILED");
    }

    return 0;
}