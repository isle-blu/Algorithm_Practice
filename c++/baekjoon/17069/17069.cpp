#include <stdio.h>

using namespace std;

int main(){
    int n;
    int home[33][33];
    long long dp[33][33][3] = {0, };

    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &home[i][j]);
        }
    }

    dp[0][1][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(home[i][j+1] == 0){
                dp[i][j+1][0] += dp[i][j][0] + dp[i][j][2]; 
            }
            if(home[i+1][j] == 0){
                dp[i+1][j][1] += dp[i][j][1] + dp[i][j][2];
            }
            if(home[i][j+1] == 0 && home[i+1][j] == 0 && home[i+1][j+1] == 0){
                dp[i+1][j+1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < 3; i++){
        ans += dp[n-1][n-1][i];
    }

    printf("%lld\n", ans);
}