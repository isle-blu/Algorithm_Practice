#include <stdio.h>
#include <vector>
using namespace std;

int N, S;
int ans = 0;

void dfs(vector<int> &seq, int sum, int idx){
    if(sum == S && idx != 0){
        ans++;    
    }
    
    for(int i = idx; i < N; i++){
        dfs(seq, sum + seq[i], i + 1);
    }
}


int main(){
    scanf("%d %d", &N, &S);

    vector<int> seq(N);

    for(int i = 0; i < N; i++){
        scanf("%d", &seq[i]);
    }

    dfs(seq, 0, 0);

    printf("%d", ans);
}