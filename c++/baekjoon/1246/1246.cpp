#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> vec(M);

    for(int i = 0; i < M; i++){
        scanf("%d", &vec[i]);
    }

    sort(vec.begin(), vec.end());

    int cnt = 1;
    int max_value = 0;
    int ans;

    for(int i = M -1; i >= 0 && cnt <= N; i--){
        if(max_value < vec[i] * cnt){
            max_value = vec[i] * cnt;
            ans = vec[i];
        }
        cnt++;
    }

    printf("%d %d", ans, max_value);
}