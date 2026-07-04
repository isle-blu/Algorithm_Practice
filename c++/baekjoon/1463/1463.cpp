#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    vector<int> dp(N+1);
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    int now = 4;
    while(now <= N){
        dp[now] = dp[now-1] + 1;
        if(now%2 == 0){
            dp[now] = min(dp[now], dp[now/2] + 1);
        }
        if(now%3 == 0){
            dp[now] = min(dp[now], dp[now/3] + 1);
        }

        now++;
    }
    
    printf("%d", dp[N]);
}

/*
2 4 6 8 10 12
3   6   9  

8 4 2 1
8 7 6 2 1

4 2 1
1 1
2 1
3 1
4 2
5 2
*/