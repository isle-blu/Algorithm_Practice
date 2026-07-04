#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
int n;
vector<pair<int, int>> eggs;

void solve(int now){
    if(now >= n){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(eggs[i].first <= 0){
                cnt++;
            }
        }

        ans = max(ans, cnt);
        return;
    }
    else if(eggs[now].first < 0){
        solve(now+1);
        return;
    }

    bool TF = true;
    
    for(int i = 0; i < n; i++){
        if(now == i || eggs[i].first < 0){
            continue;
        }
        
        TF = false;
        eggs[now].first -= eggs[i].second;
        eggs[i].first -= eggs[now].second;

        solve(now+1);

        eggs[now].first += eggs[i].second;
        eggs[i].first += eggs[now].second;
    }

    if(TF){
        solve(n);
    }
}

int main(){
    scanf("%d", &n);

    int tmp1, tmp2;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &tmp1, &tmp2);
        eggs.push_back({tmp1, tmp2});
    }

    solve(0);

    printf("%d", ans);
}