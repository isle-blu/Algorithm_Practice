#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> vec(N);

    for(int i = 0; i < N; i++){
        scanf("%d", &vec[i]);
    }

    int now = K;
    int before = 0;
    int sum = 0;
    int ans;
    for(int i = 0; i < K; i++){
        sum += vec[i];
    }

    ans = sum;

    while(now < N){
        sum += vec[now] - vec[before];
        if(ans < sum){
            ans = sum;
        }
        before++;
        now++;
    }
    
    printf("%d", ans);
}