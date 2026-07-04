#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;

int n;
vector<int> oper(4);

int max_num = INT_MIN;
int min_num = INT_MAX;

void dfs(int result, vector<int> &seq, int idx){
    if(idx == n){
        max_num = max(max_num, result);
        min_num = min(min_num, result);
        return;
    }

    if(oper[0] > 0){
        oper[0]--;
        dfs(result+seq[idx], seq, idx+1);
        oper[0]++;
    }

    if(oper[1] > 0){
        oper[1]--;
        dfs(result-seq[idx], seq, idx+1);
        oper[1]++;
    }

    if(oper[2] > 0){
        oper[2]--;
        dfs(result*seq[idx], seq, idx+1);
        oper[2]++;
    }

    if(oper[3] > 0){
        oper[3]--;
        dfs(result/seq[idx], seq, idx+1);
        oper[3]++;
    }

}

int main(){
    scanf("%d", &n);

    vector<int> seq(n);

    for(int i = 0; i < n; i++){
        scanf("%d", &seq[i]);
    }

    for(int i = 0; i < 4; i++){
        scanf("%d", &oper[i]);
    }

    dfs(seq[0], seq, 1);

    printf("%d\n%d", max_num, min_num);
}