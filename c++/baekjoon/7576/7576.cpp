#include <stdio.h>
#include <vector>
using namespace std;

int m, n;
bool TF;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool outOfRange(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= m){
        return true;
    }
    return false;
}

void dfs(vector<vector<int>> &box, vector<vector<bool>> &visited, int r, int c){
    for(int i = 0; i < 4; i++){
        int x = r + dx[i];
        int y = c + dy[i];

        if(outOfRange(x, y) || box[x][y] == -1 || visited[x][y]){
            continue;
        }

        if(box[x][y] == 1){
            TF = true;
            return;
        }

        visited[x][y] = true;
        dfs(box, visited, x, y);
    }
}

int main(){
    int sum = 0;
    int ans = 0;
    scanf("%d %d", &m, &n);

    vector<vector<int>> box(n, vector<int>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &box[i][j]);
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(box[i][j] == 0){
                sum++;
                if(!visited[i][j]){
                    TF = false;
                    visited[i][j] = true;
                    dfs(box, visited, i, j);

                    if(!TF){
                        printf("%d", -1);
                        return 0;
                    }
                }          
            }
        }
    }

    while (sum > 0){
        ans++;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(box[i][j] == 1 && !visited[i][j]){
                    visited[i][j] = true;
                    for(int k = 0; k < 4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if(outOfRange(x, y) || box[x][y] != 0 || visited[x][y]){
                            continue;
                        }

                        box[x][y] = 1;
                        visited[x][y] = true;
                        sum--;
                    }
                }
            }
        }
    }

    printf("%d", ans);
}