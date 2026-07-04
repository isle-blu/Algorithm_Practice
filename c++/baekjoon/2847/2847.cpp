#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n;
    int ans = 0;
    scanf("%d", &n);

    vector<int> score(n);
    

    for(int i = 0; i < n; i++){
        scanf("%d", &score[i]);
    }

    for(int i = n-2; i >= 0; i--){
        if(score[i] >= score[i+1]){
            int tmp = score[i];
            score[i] = score[i+1] - 1;
            ans += tmp - score[i];
        }
    }

    printf("%d", ans);
}