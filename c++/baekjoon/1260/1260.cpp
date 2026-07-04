#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
using namespace std;

void dfs(vector<set<int>> &vec, vector<bool> &visited, int before){
    visited[before] = true;
    printf("%d ", before);
    for(int i : vec[before]){
        if(visited[i]){
            continue;
        }

        dfs(vec, visited, i);
    }
}

void bfs(vector<set<int>> &vec, vector<bool> &visited, int v){
    queue<int> bfs_q;
    
    bfs_q.push(v);
    visited[v] = true;

    while (!bfs_q.empty()){
        int num = bfs_q.front();
        bfs_q.pop();

        printf("%d ", num);

        for(int i : vec[num]){
            if(visited[i]){
                continue;
            }

            bfs_q.push(i);
            visited[i] = true;
        }
    }
    
}

int main(){
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    vector<set<int>> vec(n+1);
    vector<bool> visited(n+1, false);

    int tmp1, tmp2;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &tmp1, &tmp2);
        vec[tmp1].insert(tmp2);
        vec[tmp2].insert(tmp1);
    }

    auto tmp_visited = visited;

    dfs(vec, tmp_visited, v);
    printf("\n");
    bfs(vec, visited, v);
}