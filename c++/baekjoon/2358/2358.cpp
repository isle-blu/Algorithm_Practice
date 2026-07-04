#include <stdio.h>
#include <unordered_map>
using namespace std;

int main(){
    int n, ans = 0;
    unordered_map<int, int> mapX;
    unordered_map<int, int> mapY;

    scanf("%d", &n);

    int x, y;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);

        mapX[x]++;
        mapY[y]++;
    }

    for(auto num : mapX){
        if(num.second >= 2){
            ans++;
        }
    }
    for(auto num : mapY){
        if(num.second >= 2){
            ans++;
        }
    }

    printf("%d", ans);
}