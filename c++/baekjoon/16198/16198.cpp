#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;

void solve(vector<int> &marble, int energy){
    int size = marble.size();
    
    if(size == 2){
        ans = max(ans, energy);
        return;
    }

    for(int i = 1; i < size-1; i++){
        int tmp = marble[i];
        int tmp_energy = marble[i-1] * marble[i+1];
        auto iter = marble.begin() + i;
        marble.erase(iter);
        solve(marble, energy + tmp_energy);
        marble.insert(iter, tmp);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    vector<int> marble(n);

    for(int i = 0; i < n; i++){
        scanf("%d", &marble[i]);
    }

    solve(marble, 0);

    printf("%d", ans);
}