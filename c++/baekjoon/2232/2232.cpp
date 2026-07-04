#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    int N;
    scanf("%d", &N);
    
    set<int> ans;
    vector<pair<int, int>> mine;
    vector<pair<int, int>> power;

    for(int i = 0; i < N; i++){
        int tmp;
        scanf("%d", &tmp);
        mine.push_back({i, tmp});
    }

    power = mine;
    sort(power.begin(), power.end(), cmp);

    int cnt = N;

    while(cnt > 0){
        pair<int, int> now = power.back();
        power.pop_back();
        if(mine[now.first].first != now.first){
            continue;
        }

        ans.insert(now.first);
        cnt--;

        int tmp_now = now.first;
        for(int i = tmp_now-1; i >= 0; i--){
            if(ans.find(mine[i].first) != ans.end() || mine[i].second >= mine[tmp_now].second){
                break;
            }
            else{
                mine[i].first = now.first;
                cnt--;
            }
            tmp_now--;
        }

        tmp_now = now.first;
        for(int i = tmp_now+1; i < N; i++){
            if(ans.find(mine[i].first) != ans.end() || mine[i].second >= mine[tmp_now].second){
                break;
            }
            else{
                mine[i].first = now.first;
                cnt--;
            }
            tmp_now++;
        }
    }

    for(auto a : ans){
        printf("%d\n", a+1);
    }

    return 0;
}