#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

int n, m;
int ans = 0;

void dfs(vector<unordered_set<int>> &icecream, vector<int> &chosen, int cnt, int idx){
    if(cnt == 0){
        ans++;
        return;
    }

    int size = n - cnt + 1;
    for(int i = idx; i <= size ; i++){
        bool check = true;
        for(auto c : chosen){
            if(icecream[i].find(c) != icecream[i].end()){
                check = false;
                break;
            }
        }

        if(check){
            chosen.push_back(i);
            dfs(icecream, chosen, cnt-1, i+1);
            chosen.pop_back();
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    vector<unordered_set<int>> icecream(n+1);

    int ice1, ice2;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &ice1, &ice2);
        icecream[ice1].insert(ice2);
        icecream[ice2].insert(ice1);
    }

    vector<int> chosen;
    dfs(icecream, chosen, 3, 1);

    printf("%d", ans);
}