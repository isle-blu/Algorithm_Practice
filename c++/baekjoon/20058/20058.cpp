#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> ans(2, 0);

vector<vector<int>> board;
int board_size;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool outOfRange(int a, int b){
    if(a < 0 || a >= board_size || b < 0 || b >= board_size){
        return false;
    }
    return true;
}

void melt(){
    auto tmp_board = board;
    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size; j++){
            if(tmp_board[i][j] == 0){
                continue;
            }
            int melted = 0;
            for(int k = 0; k < 4; k++){
                if(!outOfRange(i+dx[k], j+dy[k]) || tmp_board[i+dx[k]][j+dy[k]] == 0){
                    melted++;    
                }
                if(melted > 1){
                    board[i][j]--;
                    ans[0]--;
                    melted = 0;
                    break;
                }
            }
        }
    }
}

void spin(int storm_size, int row, int column){
    vector<vector<int>> tmp_board;

    for(int i = column; i < column + storm_size; i++){
        vector<int> vec;
        for(int j = row + storm_size - 1; j >= row; j--){
            vec.push_back(board[j][i]);
        }
        tmp_board.push_back(vec);
    }

    for(int i = row; i < row+storm_size; i++){
        for(int j = column; j < column+storm_size; j++){
            board[i][j] = tmp_board[i - row][j - column];
        }
    }
}

void fireStorm(int level){
    int storm_size = pow(2, level);
    
    for(int i = 0; i < board_size; i+=storm_size){
        for(int j = 0; j < board_size; j+=storm_size){
            spin(storm_size, i, j);
        }    
    }

    melt();
}

void bfs(int row, int column){
    queue<pair<int, int>> bfs_q;
    bfs_q.push({row, column});
    board[row][column] = 0;

    int size = 1;
    while(!bfs_q.empty()){
        int x = bfs_q.front().first;
        int y = bfs_q.front().second;
        bfs_q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(outOfRange(nx, ny) && board[nx][ny] > 0){
                bfs_q.push({nx, ny});
                board[nx][ny] = 0;
                size++;
            }
        }
    }

    if(size > ans[1]){
        ans[1] = size;
    }
}

int main(){
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    board_size = pow(2, N);

    for(int i = 0; i < board_size; i++){
        vector<int> vec(board_size);
        for(int j = 0; j < board_size; j++){
            scanf("%d", &vec[j]);
            ans[0] += vec[j];
        }
        board.push_back(vec);
    }

    int level;
    for(int i = 0; i < Q; i++){
        scanf("%d", &level);
        fireStorm(level);
    }

    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size; j++){
            if(board[i][j] > 0){
                bfs(i, j);
            }
        }
    }

    printf("%d\n%d", ans[0], ans[1]);

    return 0;
}