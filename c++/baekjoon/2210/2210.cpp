#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int ans = 0;

vector<vector<char>> board(5, vector<char>(5));
unordered_set<string> integer_set;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool outOfRange(int r, int c){
    if(r < 0 || c < 0 || r >= 5 || c >= 5){
        return true;
    }
    return false;
}


void dfs(string str, int r, int c, int cnt){
    if(cnt == 6){
        if(integer_set.find(str) == integer_set.end()){
            integer_set.insert(str);
            ans++;
        }
        return;
    }

    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(!outOfRange(nr, nc)){
            dfs(str + board[nr][nc], nr, nc, cnt+1);
        }
    }
}


int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            scanf(" %c", &board[i][j]);
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            string now;
            now += board[i][j];
            dfs(now, i, j, 1);
        }
    }

    printf("%d", ans);
}