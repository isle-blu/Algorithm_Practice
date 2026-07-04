#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <limits.h>
using namespace std;

int N, M;

struct coordinate
{
    int d, r, c;

    bool operator < (const coordinate c) const{
        return d > c.d;
    }
};

int ans[2];

vector<string> forest(50);
vector<vector<int>> graph(50, vector<int>(50, 0));
vector<vector<int>> dist(50, vector<int>(50, INT_MAX));
priority_queue<coordinate> pq; 

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool outOfRange(int r, int c){
    if(r < 0 || c < 0 || r >= N || c >= M){
        return true;
    }
    return false;
}

void dijkstra(){
    while (!pq.empty())
    {
        int d = pq.top().d;
        int r = pq.top().r;
        int c = pq.top().c;
        pq.pop();

        if(forest[r][c] == 'F'){
            ans[0] = d/2500;
            ans[1] = d%2500;
            return;
        }

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(outOfRange(nr, nc)){
               continue;
            }

            int nd = d + graph[nr][nc];
            if(dist[nr][nc] > nd){
                dist[nr][nc] = nd;
                pq.push({nd, nr, nc});
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);

    int row, column;

    for(int i = 0; i < N; i++){
        char tmp[51];
        scanf("%s", &tmp);
        forest[i] = tmp;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(forest[i][j] == 'S'){
                dist[i][j] = 0;
                pq.push({0, i, j});
            }
            else if(forest[i][j] == 'g'){
                graph[i][j] = 2500;
                for(int k = 0; k < 4; k++){
                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if(!outOfRange(ni, nj) && forest[ni][nj] == '.'){
                        graph[ni][nj] = 1;
                    }
                }
            }
        }
    }

    graph[row][column] = 0;

    dijkstra();

    printf("%d %d", ans[0], ans[1]);
}