#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int ans = 0;

void dfs(vector<int> &cards, int sum, int idx, int cnt){
    if(sum > m){
        return;
    }
    else if(cnt == 0){
        ans = max(ans, sum);
    }

    for(int i = idx; i <= n-cnt; i++){
        dfs(cards, sum + cards[i], i+1, cnt-1);
    }
}

int main(){
    scanf("%d %d", &n, &m);

    vector<int> cards(n);

    for(int i = 0; i < n; i++){
        scanf("%d", &cards[i]);
    }

    dfs(cards, 0, 0, 3);

    printf("%d", ans);
}
