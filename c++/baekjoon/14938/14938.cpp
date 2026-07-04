#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r;
int ans = 0;

void dijkstra(vector<vector<int>> field, vector<int> &items, int start){
    vector<int> d(n+1, -1);
    priority_queue<pair<int, int>> pq;

    pq.push({start, 0});
    d[start] = 0;

    while(!pq.empty()){
        int current = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        for(int i = 1; i <= n; i++){
            if(i == current){
                continue;
            }

            if(field[current][i] > 0 && distance + field[current][i] <= m){
                d[i] = distance + field[current][i];
                pq.push({i, d[i]});
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++ ){
        if(d[i] >= 0){
            cnt += items[i];
        }
    }

    ans = max(ans, cnt);
}


int main(){
    scanf("%d %d %d", &n, &m, &r);

    vector<int> items(n+1);
    vector<vector<int>> field(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; i++){
        scanf("%d", &items[i]);
    }

    for(int i = 0; i < r; i++){
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);

        field[a][b] = l;
        field[b][a] = l;
    }

    for(int i = 1; i <= n; i++){
        dijkstra(field, items, i);
    }

    printf("%d", ans);
}