#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool boundary(int nx, int ny){
    if(nx < 0 || nx >= N || ny < 0 || ny >= M){
        return false;
    }
    return true;
}

bool bfs(int row, int column, vector<vector<char>> &board, vector<vector<int>> &visited, int check){
    queue<pair<int, int>> bfs_q;
    bfs_q.push({row, column});
    visited[row][column] = check;

    while (!bfs_q.empty())
    {
        int x = bfs_q.front().first;
        int y = bfs_q.front().second;
        bfs_q.pop();

        int nx, ny, dir;
        switch (board[x][y])
        {
        case 'N':
            dir = 0;
            break;
        case 'S':
            dir = 1;
            break;
        case 'W':
            dir = 2;
            break;
        case 'E':
            dir = 3;
            break;
        }

        nx = x + dx[dir];
        ny = y + dy[dir];

        if(boundary(nx, ny)){
            if(visited[nx][ny] == 0){
                visited[nx][ny] = check;
                bfs_q.push({nx, ny});
            }
            else if(visited[nx][ny] < check){
                return false;
            }
            else{
                break;
            }
        }
    }
    return true;
}

int main(){
    scanf("%d %d", &N, &M);

    vector<vector<char>> board(N, vector<char>(M));
    vector<vector<int>> visited(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %c", &board[i][j]);
        }

    }

    int check = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] == 0){
                if(bfs(i, j, board, visited, check)){
                    ans++;
                }
                check++;
            }
        }
    }

    printf("%d", ans);

    return 0;
}

/*
3 4
NNNN
WWEE
SSSS
*/