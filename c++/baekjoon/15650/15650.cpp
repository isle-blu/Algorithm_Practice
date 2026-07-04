#include <stdio.h>
#include <vector>
using namespace std;

int n, m, loop_size;
vector<int> vec;

void dfs(int before, int cnt){
    if(cnt == m){
        for(int num : vec){
            printf("%d ", num);
        }
        printf("\n");
        return;
    }

    for(int i = before + 1; i <= n; i++){
        vec.push_back(i);
        dfs(i, cnt+1);
        vec.pop_back();
    }
    
}

int main(){
    scanf("%d %d", &n, &m);

    loop_size = n - m + 1;
    for(int i = 1; i <= loop_size; i++){
        vec.push_back(i);
        dfs(i, 1);
        vec.pop_back();
    }
}