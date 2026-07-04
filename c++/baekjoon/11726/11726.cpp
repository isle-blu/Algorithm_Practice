#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> dp(n+1);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i = 4; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i]%10007;
    }

    printf("%d", dp[n]);
}

/*

12345 + 54321 = 66666 -> 6624
2338 + 4286 = 6624

*/
