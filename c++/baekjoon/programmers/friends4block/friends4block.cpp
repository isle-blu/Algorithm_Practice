#include <string>
#include <vector>

using namespace std;

int dr[4] = {0, 0, 1, 1};
int dc[4] = {0, 1, 1, 0};

bool outOfRange(int r, int c, int m, int n){
    if(r < 0 || c < 0 || r >= m || c >= n){
        return true;
    }
    return false;
}

int check(vector<string> &board, vector<vector<bool>> &brocken, int row, int column, int m, int n){
    int cnt = 0;
    int check_cnt = 0;
    
    vector<vector<bool>> tmp = brocken;
    for(int i = 0; i < 4; i++){
        int nr = row + dr[i];
        int nc = column + dc[i];
        
        if(!outOfRange(nr, nc, m, n) && board[nr][nc] == board[row][column]){
            tmp[nr][nc] = true;
            check_cnt++;
            if(!brocken[nr][nc]){
                cnt++;
            }
        }
        else{
            break;
        }
    }
    
    if(check_cnt == 4){
        brocken = tmp;
        return cnt;
    }
    return 0;
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<vector<bool>> brocken(m, vector<bool>(n, false));
    
    while(true){
        int cnt = answer;
        
        vector<vector<bool>> tmp = brocken;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != 'X'){
                    cnt += check(board, tmp, i, j, m, n);
                }
            }
        }
        
        if(cnt == answer){
            break;
        }
        answer = cnt;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(tmp[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    for(int k = i; k > 0 && board[k-1][j] != 'X'; k--){
                        board[k][j] = board[k-1][j];
                        board[k-1][j] = 'X';
                    }
                }
            }
        }
    }
    
    
    return answer;
}