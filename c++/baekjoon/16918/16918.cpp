#include <stdio.h>
#include <vector>
using namespace std;

int R, C, N;
vector<vector<int>> board;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool outOfRange(int r, int c){
    if(r < 0 || r >= R || c < 0 || c >= C){
        return true;
    }
    return false;
}

void bomb_plus(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            board[i][j]++;
        }
    }
}

void explode(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[i][j] == 3){
                board[i][j] = -1;
                for(int k = 0; k < 4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if(!outOfRange(nr, nc) && board[nr][nc] < 3 && board[nr][nc] > 0){
                        board[nr][nc] = -1;
                    }
                }
            }
        }
    }
}

int main(){
    

    scanf("%d %d %d", &R, &C, &N);

    for(int i = 0; i < R; i++){
        vector<int> vec;
        char tmp;
        for(int j = 0; j < C; j++){
            scanf(" %c", &tmp);
            if(tmp == '.'){
                vec.push_back(-1);
            }
            else if(tmp == 'O'){
                vec.push_back(1);
            }
        }
        board.push_back(vec);
    }

    for(int i = 2; i <= N; i++){
        bomb_plus();
        explode();
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[i][j] == -1){
                printf(".");
            }
            else{
                printf("O");
            }
        }
        printf("\n");
    }
}