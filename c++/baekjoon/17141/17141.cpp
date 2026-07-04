#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ans = 2501; // 50 * 50 칸 수보다 크게
int n, m;
vector<vector<int>> lab(51, vector<int>(51)); // 연구소 배열
vector<pair<int, int>> virus; // 바이러스 놓을 수 있는 위치
queue<pair<int, int>> now_virus; // 현재 시간에 퍼질 바이러스

// 이동을 위한 배열
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// 범위를 넘어가는 지 확인
bool outOfRange(int r, int c){
    if(r < 0 || c < 0 || r >= n || c >= n){
        return true;
    }
    return false;
}

// 바이러스가 퍼지지 않은 장소 확인
bool check(vector<vector<bool>> &visited){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && lab[i][j] != 1){
                return false;
            }
        }
    }    
    return true;
}

// 바이러스 확산
void dfs(vector<vector<bool>> &visited, int cnt){
    int size =  now_virus.size(); // 현재 시간에 퍼질 위치의 수

    if(size == 0){  // 더이상 바이러스가 퍼질 수 없는 경우
        // 퍼지지 않은 위치가 있는 지 확인
        if(check(visited)){
            ans = min(ans, --cnt); // 모두 퍼진 경우, ans와 cnt중 작은 수 ans에 저장
        }

        return;
    }

    for(int i = 0; i < size; i++){
        // 현재 확인할 좌표
        int r = now_virus.front().first;
        int c = now_virus.front().second;
        now_virus.pop();

        // 상하좌우 확인
        for(int j = 0; j < 4; j++){
            int nr = r + dr[j];
            int nc = c + dc[j];

            // 연구소 범위 초과하는지, 방문한 좌표인지, 벽인지 아닌지 확인
            if(!outOfRange(nr, nc) && !visited[nr][nc] && lab[nr][nc] != 1){
                visited[nr][nc] = true; // 방문 여부 true로 변경
                now_virus.push({nr, nc}); // queue에 해당 좌표 삽입
            }
        }
    }

    dfs(visited, cnt+1); // 다음 시간(1초)에 확산을 위한 재귀
}

int main(){
    scanf("%d %d", &n, &m);

    // 연구소 구조 입력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &lab[i][j]);

            // 바이러스를 퍼뜨릴수 있는 좌표 저장
            if(lab[i][j] == 2){
                virus.push_back({i, j});
            }
        }
    }


    int size = virus.size();
    
    // 조합을 위한 배열 생성
    vector<int> comb(size, 1);
    for(int i = 0; i < size - m; i++){
        comb[i] = 0;
    }

    // 바이러스를 퍼뜨릴 좌표 조합
    do{
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // 방문여부 확인
        for(int i = 0; i < virus.size(); i++){
            if(comb[i] == 1){
                now_virus.push(virus[i]); // 이번 조합에서 시작할 바이러스 위치 저장
                visited[virus[i].first][virus[i].second] = true; // 해당 바이러스 위치 방문여부를 true로 변경
            }
        }

        dfs(visited, 0); // 바이러스 확산

    }while(next_permutation(comb.begin(), comb.end())); // 다음 조합으로 변경

    // ans값이 초기값에서 변하지 않은 경우 -> 바이러스가 퍼지지 않는 좌표 존재
    if(ans == 2501){
        ans = -1;
    }

    printf("%d", ans);

    return 0;
}


/*
바이러스 M개
연구소 N*N
5 <= N <= 50
1 <= M <= 10
0 - 빈칸, 1 - 벽, 2 - 바이러스 가능

7 3
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
*/