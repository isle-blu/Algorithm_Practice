#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &tree, vector<int> &ans){
    queue<int> bfs_q;

    bfs_q.push(1);
    ans[1] = 0;
    
    while (!bfs_q.empty())
    {
        int parent = bfs_q.front();
        int size = tree[parent].size();
        bfs_q.pop();

        for(int i = 0; i < size; i++){
            int node = tree[parent][i];
            if(ans[node] == -1){
                ans[node] = parent;
                bfs_q.push(node);
            }
        }
    }
    
}

int main(){
    int n, node1, node2;
    scanf("%d", &n);

    vector<vector<int>> tree(n+1);
    vector<int> ans(n+1, -1);

    for(int i = 1; i < n; i++){
        scanf("%d %d", &node1, &node2);
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    bfs(tree, ans);

    for(int i = 2; i <= n; i++){
        printf("%d\n", ans[i]);
    }
}