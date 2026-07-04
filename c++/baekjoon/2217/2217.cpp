#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    int ans = 0;
    scanf("%d", &n);

    vector<int> ropes(n);

    for(int i = 0; i < n; i++){
        scanf("%d", &ropes[i]);
    }

    sort(ropes.begin(), ropes.end(), cmp);

    while(n > 0){
        int weight = ropes.back() * n;
        ans = max(ans, weight);

        n--;
        ropes.pop_back();
    }

    printf("%d", ans);
}