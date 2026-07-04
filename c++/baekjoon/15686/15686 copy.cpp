#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int ans = INT_MAX;

int N, M;
vector<vector<int>> city;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;


 
//처음에 bfs로 했다가 메모리 초과 뜸;;
void find_house(vector<pair<int, int>> &selected){
    int sum = 0;
    for(auto house : houses){
        int distance = INT_MAX;
        for(auto select : selected){
            int tmp_distance = abs(select.first - house.first) + abs(select.second - house.second);
            if(distance > tmp_distance){
                distance = tmp_distance;
            }
        }
        sum += distance;
    }
    if(sum < ans){
        ans = sum;
    }
}

void select_chicken(int size, int idx, vector<pair<int, int>> &selected){
    if(size < 0){
        find_house(selected);
        return;
    }

    for(int i = idx; i < chickens.size() - size; i++){
        int x = chickens[i].first;
        int y = chickens[i].second;

        selected.push_back({x, y});
        select_chicken(size-1, i+1, selected);
        selected.pop_back();
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        int tmp;
        for(int j = 0; j < N; j++){
            cin >> tmp;
            if(tmp == 1){
                houses.push_back({i, j});
            }
            if(tmp == 2){
                chickens.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> selected;

    select_chicken(M - 1, 0, selected);

    cout << ans << endl;

    return 0;
}