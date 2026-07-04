#include <stdio.h>
#include <vector>
using namespace std;

int N;

bool outOfRange(int r, int c){
    if(r >= N || c >= N){
        return true;
    }
    return false;
}

int main(){
    scanf("%d", &N);

    vector<vector<int>> vec(N, vector<int>(N));
    vector<vector<long long>> dp(N, vector<long long>(N, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &vec[i][j]);
        }
    }


    dp[0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dp[i][j] == 0){
                continue;
            }

            if(i == N - 1 && j == N -1){
                break;
            }

            int r, c;

            r = i;
            c = j + vec[i][j];

            if(!outOfRange(r, c)){
                dp[r][c] += dp[i][j];
            }

            r = i + vec[i][j];
            c = j;

            if(!outOfRange(r, c)){
                dp[r][c] += dp[i][j];
            }
        }
    }

    printf("%lld", dp[N-1][N-1]);
}