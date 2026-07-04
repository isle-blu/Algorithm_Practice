#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 64;

void solve(vector<vector<char>> &chess, int end_r, int end_c, int now_r, int now_c, char before, int cnt){
    if(now_r > end_r){
        ans = min(ans, cnt);
        return;
    }

    char now = before == 'B' ? 'W' : 'B';

    if(before == chess[now_r][now_c]){
        cnt++;        
    }

    if(now_c == end_c){
        solve(chess, end_r, end_c, now_r+1, end_c-7, before, cnt);
    }
    else{
        solve(chess, end_r, end_c, now_r, now_c+1, now, cnt);
    }
}


int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<char>> chess(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ;j++){
            scanf(" %c", &chess[i][j]);
        }
    }

    int loop_n = n - 7;
    int loop_m = m - 7;

    for(int i = 0; i < loop_n; i++){
        for(int j = 0; j < loop_m; j++){
            solve(chess, i+7, j+7, i, j, 'B', 0);
            solve(chess, i+7, j+7, i, j, 'W', 0);
        }
    }

    printf("%d", ans);
}