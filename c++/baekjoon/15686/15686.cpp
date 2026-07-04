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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct Position{
    int r;
    int c;
    int distance;
};



bool outOfRange(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N){
        return true;
    }
    return false;
}

int bfs(int r, int c){
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<Position> bfs_q;

    bfs_q.push({r, c, 0});
    visited[r][c] = true;

    while(!bfs_q.empty()){
        int x = bfs_q.front().r;
        int y = bfs_q.front().c;
        int distance = bfs_q.front().distance;
        bfs_q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!outOfRange(nx, ny)){
                if(city[nx][ny] == 3){
                    return distance + 1;
                }
                else if(!visited[nx][ny]){
                    bfs_q.push({nx, ny, distance+1});
                }
            }
        }
    }

    return 0;
}

void find_house(){
    int sum = 0;
    for(auto house : houses){
        sum += bfs(house.first, house.second);
    }
    if(sum < ans){
        ans = sum;
    }
}

void select_chicken(int size, int idx){
    if(size < 0){
        find_house();
        return;
    }

    for(int i = idx; i < chickens.size() - size; i++){
        int x = chickens[i].first;
        int y = chickens[i].second;

        city[x][y] = 3;
        select_chicken(size - 1, i + 1);
        city[x][y] = 2;
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        vector<int> vec(N);
        for(int j = 0; j < N; j++){
            cin >> vec[j];
            if(vec[j] == 1){
                houses.push_back({i, j});
            }
            if(vec[j] == 2){
                chickens.push_back({i, j});
            }
        }
        city.push_back(vec);
    }

    select_chicken(M - 1, 0);

    cout << ans << endl;

    return 0;
}