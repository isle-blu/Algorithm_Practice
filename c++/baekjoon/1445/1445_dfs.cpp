#include <stdio.h>
#include <vector>
using namespace std;

int N, M;
int garbage = 2500;
int semi_garbage = 2500;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool outOfRange(int r, int c){
    if(r < 0 || c < 0 || r >= N || c >= M){
        return true;
    }
    return false;
}

void dfs(vector<vector<char>> &forest, vector<vector<bool>> &visited, int row, int column, int cnt_g, int cnt_semi){    
    if(forest[row][column] == 'g'){
        cnt_g++;
        if(cnt_g > garbage){
            return;
        }
    }
    else if(forest[row][column] == 'F'){
        if(garbage > cnt_g){
            garbage = cnt_g;
            semi_garbage = cnt_semi;
        }
        else if(garbage == cnt_g && semi_garbage > cnt_semi){
            semi_garbage = cnt_semi;
        }

        return;
    }
    
    bool semi_TF = true;
    vector<pair<int, int>> move;
    
    for(int i = 0; i < 4; i++){
        int nr = row + dr[i];
        int nc = column + dc[i];

        if(outOfRange(nr, nc)){
            continue;
        }

        if(forest[row][column] == '.' && semi_TF && forest[nr][nc] == 'g'){
            semi_TF = false;
            cnt_semi++;
        }

        if(!visited[nr][nc]){
            move.push_back({nr, nc});
        }
    }

    for(auto m : move){
        visited[m.first][m.second] = true;
        dfs(forest, visited, m.first, m.second, cnt_g, cnt_semi);
        visited[m.first][m.second] = false;
    }
}

int main(){
    scanf("%d %d", &N, &M);

    vector<vector<char>> forest(N, vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int row, column, cnt_semi;


    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %c", &forest[i][j]);
            if(forest[i][j] == 'S'){
                row = i;
                column = j;
            }
        }
    }

    visited[row][column] = true;
    dfs(forest, visited, row, column, 0, 0);

    printf("%d %d", garbage, semi_garbage);
}