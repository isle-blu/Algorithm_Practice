#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n;
int ans = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool outOfRange(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= n){
        return true;
    }
    return false;
}

bool check(vector<vector<char>> &board, char color, int r, int c){
    if(color == 'B'){
        return board[r][c] != 'B';
    }

    return board[r][c] == 'B';
}

void bfs1(vector<vector<char>> &board, vector<vector<bool>> &visited, int r, int c){
    queue<pair<int, int>> bfs_q;
    char color = board[r][c];

    bfs_q.push({r, c});
    visited[r][c] = true;

    while(!bfs_q.empty()){
        int x = bfs_q.front().first;
        int y = bfs_q.front().second;
        bfs_q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(outOfRange(nx, ny) || visited[nx][ny] || board[nx][ny] != color){
                continue;
            }

            bfs_q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

void bfs2(vector<vector<char>> &board, vector<vector<bool>> &visited, int r, int c){
    queue<pair<int, int>> bfs_q;
    char color = board[r][c];

    bfs_q.push({r, c});
    visited[r][c] = true;

    while(!bfs_q.empty()){
        int x = bfs_q.front().first;
        int y = bfs_q.front().second;
        bfs_q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(outOfRange(nx, ny) || visited[nx][ny] || check(board, color, nx, ny)){
                continue;
            }

            bfs_q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}


int main(){  
    scanf("%d", &n);

    vector<vector<char>> board(n, vector<char>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            scanf(" %c", &board[i][j]);
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    auto tmp_visited = visited;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            if(!tmp_visited[i][j]){
                bfs1(board, tmp_visited, i, j);
                ans++;
            }
        }
    }

    printf("%d ", ans);

    ans = 0;

    tmp_visited = visited;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            if(!tmp_visited[i][j]){
                bfs2(board, tmp_visited, i, j);
                ans++;
            }
        }
    }

    printf("%d", ans);
}