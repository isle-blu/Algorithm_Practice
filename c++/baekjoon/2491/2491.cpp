#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int ans = 1;
    scanf("%d", &n);

    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        scanf("%d", &vec[i]);
    }

    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(vec[i] >= vec[i-1]){
            cnt++;
        }
        else{
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);

    cnt = 1;
    for(int i = 1; i < n; i++){
        if(vec[i] <= vec[i-1]){
            cnt++;
        }
        else{
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);

    printf("%d", ans);
}