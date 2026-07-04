#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, K;
    queue<int> q;
    vector<int> ans;
    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; i++){
        q.push(i);
    }

    int size = 0;

    while(!q.empty()){
        for(int i = 1; i < K; i++){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        ans.push_back(q.front());
        q.pop();
    }

    printf("<");
    for(int i = 0; i < N-1; i++){
        printf("%d, ", ans[i]);
    }
    printf("%d", ans.back());
    printf(">");
}