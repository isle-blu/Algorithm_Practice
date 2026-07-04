#include <stdio.h>
#include <vector>
using namespace std;

int n;
int rain  = 1;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool outOfRange(int r, int c){
    if(r < 0 || c < 0 || r >= n || c >= n){
        return true;
    }
    return false;
}

void dfs(vector<vector<int>> &area, vector<vector<bool>> &visited, int r, int c){
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(outOfRange(nr, nc) || visited[nr][nc] || area[nr][nc] <= rain){
            continue;
        }

        visited[nr][nc] = true;
        dfs(area, visited, nr, nc);
    }
}

int main(){
    bool TF = true;
    int ans = 1;

    scanf("%d", &n);

    vector<vector<int>> area(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &area[i][j]);
        }
    }

    while(true){
        int cnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(area[i][j] > rain && !visited[i][j]){
                    cnt++;
                    dfs(area, visited, i, j);
                }
            }
        }

        if(cnt == 0){
            break;
        }

        if(cnt > ans){
            ans = cnt;
        }

        rain++;
    }

    printf("%d", ans);
}