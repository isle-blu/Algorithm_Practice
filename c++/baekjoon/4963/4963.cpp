#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int dr[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool outOfRange(int r, int c){
    if(r < 0 || c < 0 || r >= m || c >= n){
        return true;
    }
    return false;
}

void bfs(int row, int column, vector<vector<int>> &map){
    queue<pair<int, int>> bfs_q;

    bfs_q.push({row, column});
    while (!bfs_q.empty())
    {
        int r = bfs_q.front().first;
        int c = bfs_q.front().second;
        bfs_q.pop();

        for(int i = 0; i < 8; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!outOfRange(nr, nc) && map[nr][nc] == 1){
                map[nr][nc] = -1;
                bfs_q.push({nr, nc});
            }
        }
    }
}

int main(){
    while(true){
        scanf("%d %d", &n, &m);
        if(n == 0){
            break;
        }

        int cnt = 0;

        vector<vector<int>> map(m, vector<int>(n));

        for(int i = 0;  i < m; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &map[i][j]);
            }
        }

        for(int i = 0;  i < m; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] == 1){
                    map[i][j] == -1;
                    cnt++;
                    bfs(i, j, map);
                }
            }
        }

        printf("%d\n", cnt);
    }
}