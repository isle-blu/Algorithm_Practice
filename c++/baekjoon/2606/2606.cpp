#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int ans = 0;
queue<int> q;
stack<int> s;
vector<int> virus(101, 0);

void bfs(vector<vector<int>> &graph, int virusNode)
{
    auto iter = graph[virusNode].begin();
    while (iter != graph[virusNode].end())
    {
        if (virus[*iter] == 0)
        {
            q.push(*iter);
            virus[*iter] = 1;
            ans++;
        }
        iter++;
    }
}

void dfs(vector<vector<int>> &graph, int virusNode)
{
    auto iter = graph[virusNode].begin();
    while (iter != graph[virusNode].end())
    {
        if (virus[*iter] == 0)
        {
            s.push(*iter);
            virus[*iter] = 1;
            ans++;
        }
        iter++;
    }
}

int main()
{
    int N, connect;
    scanf("%d\n%d", &N, &connect);

    vector<vector<int>> graph(N + 1);

    int node1;
    int node2;
    for (int i = 0; i < connect; i++)
    {
        scanf("%d %d", &node1, &node2);
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    q.push(1);
    //s.push(1);
    virus[1] = 1;

    int tmp;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();

        bfs(graph, tmp);
    }

    /*
    int tmp;
    while (!s.empty())
    {
        tmp = s.top();
        s.pop();

        dfs(graph, tmp);
    }
    */

    printf("%d", ans);

    return 0;
}
