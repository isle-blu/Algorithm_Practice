#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans = 0;

void climb(vector<int> &stair, int cnt, int sum, int idx){
    if(idx == n - 1){
        ans = max(ans, sum);
        return;
    }

    if(cnt < 2 && idx+1 < n){
        climb(stair, cnt+1, sum+stair[idx+1], idx+1);
    }

    if(idx+2 < n){
        climb(stair, 1, sum+stair[idx+2], idx+2);
    }
}

int main(){
    scanf("%d", &n);

    vector<int> stair(n);

    for(int i = 0; i < n; i++){
        scanf("%d", &stair[i]);
    }

    climb(stair, 1, stair[0], 0);
    climb(stair, 1, stair[1], 1);

    printf("%d", ans);
}