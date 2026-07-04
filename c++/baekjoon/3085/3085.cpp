#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
int N;

void checkColumn(int r, int c, vector<vector<char>> &box){
    int cnt = 1;

    for(int i = r-1; i >= 0; i--){
        if(box[i][c] != box[r][c]){
            break;
        }
        cnt++;
    }
    for(int i = r+1; i < N; i++){
        if(box[i][c] != box[r][c]){
            break;
        }
        cnt++;
    }

    ans = max(ans, cnt);
}

void checkRow(int r, int c, vector<vector<char>> &box){
    int cnt = 1;

    for(int i = c-1; i >= 0; i--){
        if(box[r][i] != box[r][c]){
            break;
        }
        cnt++;
    }
    for(int i = c+1; i < N; i++){
        if(box[r][i] != box[r][c]){
            break;
        }
        cnt++;
    }

    ans = max(ans, cnt);
}




int main(){
    scanf("%d", &N);

    vector<vector<char>> box(N, vector<char>(N));
    vector<vector<bool>> visitedRow(N, vector<bool>(N, false));
    vector<vector<bool>> visitedColumn(N, vector<bool>(N, false));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf(" %c", &box[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != N-1 && box[i][j] == box[i+1][j]){
                checkColumn(i, j, box);
            }
            if(j != N-1 && box[i][j] == box[i][j+1]){
                checkRow(i, j, box);
            }
        }
    }



    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != N-1){
                char tmp = box[i][j];
                box[i][j] = box[i+1][j];
                box[i+1][j] = tmp;

                checkColumn(i, j, box);
                checkRow(i, j, box);
                checkColumn(i+1, j, box);
                checkRow(i+1, j, box);

                box[i+1][j] = box[i][j];
                box[i][j] = tmp;
            }
            
            if(j != N-1){
                char tmp = box[i][j];
                box[i][j] = box[i][j+1];
                box[i][j+1] = tmp;

                checkColumn(i, j, box);
                checkRow(i, j, box);
                checkColumn(i, j+1, box);
                checkRow(i, j+1, box);

                box[i][j+1] = box[i][j];
                box[i][j] = tmp;
            }
        }
    }

    printf("%d", ans);
}