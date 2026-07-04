#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> cardPack(n+1);
    vector<int> DP;

    for(int i = 1; i <= n; i++){
        scanf("%d", &cardPack[i]);
    }

    DP = cardPack;

    DP[1] = cardPack[1];
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            DP[i] = max(DP[i], DP[j] + DP[i-j]);
        }
    }
    

    printf("%d", DP[n]);
}