#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> dp(n+1);

    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }

    printf("%d", dp[n]);
}

/*
3 -> 3

001
100

111

4 -> 5

0011
1001
1100
0000
1111

5 -> 8

11111
00111
10011
11001
11100
00001
10000
00100

7

6

111111

001111 -> 5
100111
110011
111001
111100

000011 -> 3

000000 -> 1

10
*/