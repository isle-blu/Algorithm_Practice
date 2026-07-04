#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

multiset<int> ans; // 정답을 저장할 multiset // 3 3 5 7

int n; // 지도 크기
vector<vector<char>> map; //지도 0 -> 빈 곳, 1 -> 건물, 2 -> 이미 체크된 건물

// 방향 
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};


// 범위 체크
bool outOfRange(int r, int c){
    if(r < 0 || c < 0 || r >= n || c >= n){
        return true;
    }
    return false;
}


// 그래프(지도) 탐색
void bfs(int row, int column){
    queue<pair<int, int>> bfs_q;
    int cnt = 1; // 단지수 

    bfs_q.push({row, column});

    while(!bfs_q.empty()){
        int r = bfs_q.front().first;
        int c = bfs_q.front().second;
        bfs_q.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 범위 초과X, 체크하지 않은 단지인 경우
            if(!outOfRange(nr, nc) && map[nr][nc] == '1'){
                map[nr][nc] = '2'; // 건물 체크
                cnt++; // 단지 수 증가
                bfs_q.push({nr, nc}); // 큐에 삽입
            }
        }
    }

    ans.insert(cnt);//set에 추가
}


int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        vector<char> vec(n);
        for(int j = 0; j < n; j++){
            scanf(" %c", &vec[j]);
        }
        map.push_back(vec);
    }

    // 그래프 탐색
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // 단지가 있을 때
            if(map[i][j] == '1'){
               map[i][j] = '2';
               bfs(i, j);
            }
        }
    }

    printf("%d\n", ans.size());

    for(auto i : ans){
        printf("%d\n", i);
    }
}