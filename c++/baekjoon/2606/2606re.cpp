#include <stdio.h>
#include <vector>
using namespace std;

int n, m;
int ans = 0;


void dfs(vector<vector<int>> &coms, vector<bool> &visited, int now){
    for(int com : coms[now]){
        if(!visited[com]){
            ans++;
            visited[com] = true;
            dfs(coms, visited, com);
        }
    }
}

int main(){
    scanf("%d\n%d", &n, &m);

    vector<vector<int>> coms(n+1);
    vector<bool> visited(n+1, false);

    int tmp1, tmp2;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &tmp1, &tmp2);

        coms[tmp1].push_back(tmp2);
        coms[tmp2].push_back(tmp1);
    }

    visited[1] = true;
    dfs(coms, visited, 1);

    printf("%d", ans);
}