#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<bool> &collegeMate, vector<vector<int>> &friends){
    int cnt = 0;
    queue<pair<int, int>> bfs_q;
    bfs_q.push({1, 0});
    collegeMate[1] = true;

    while(!bfs_q.empty()){
        int mate = bfs_q.front().first;
        int friend_cnt = bfs_q.front().second;
        bfs_q.pop();

        if(friend_cnt == 2){
            break;
        }

        for(int f : friends[mate]){
            if(!collegeMate[f]){
                collegeMate[f] = true;
                bfs_q.push({f, friend_cnt+1});
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    int n, m;
    scanf("%d\n%d", &n, &m);

    vector<bool> collegeMate(n+1, false);
    vector<vector<int>> friends(n+1);

    for(int i = 0; i < m; i++){
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);

        friends[tmp1].push_back(tmp2);
        friends[tmp2].push_back(tmp1);
    }

    printf("%d", bfs(collegeMate, friends));

}