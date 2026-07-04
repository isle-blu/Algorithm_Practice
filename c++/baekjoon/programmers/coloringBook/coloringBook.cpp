#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.


// 범위 체크
bool outOfRange(int r, int c, int m, int n){
    if(r < 0 || c < 0 || r >= m || c >= n){
        return true;
    }
    return false;
}


int bfs(vector<vector<int>> &picture, vector<vector<bool>> &visited, int row, int column, int dr[4], int dc[4], int m, int n){
    queue<pair<int, int>> bfs_q;
    int cnt = 1;
    int color = picture[row][column];
    
    bfs_q.push({row, column});
    while(!bfs_q.empty()){
        int r = bfs_q.front().first;
        int c = bfs_q.front().second;
        bfs_q.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!outOfRange(nr, nc, m, n) && !visited[nr][nc] && picture[nr][nc] == color){
                bfs_q.push({nr, nc});
                visited[nr][nc] = true;
                cnt++;
            }
        }
    }
    
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    vector<vector<bool>> visited(m, vector<bool>(n, false)); // 방문 체크
    
    // 방향 결정
    int dr[4] = {0, 0, 1, -1}; 
    int dc[4] = {1, -1, 0, 0};
    
    //영역 체크
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && picture[i][j] != 0){
                visited[i][j] = true;
                answer[0]++;
                answer[1] = max(answer[1], bfs(picture, visited,i, j, dr, dc, m, n));
            }
        }
    }
       
    return answer;
}