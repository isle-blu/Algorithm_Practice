#include <stdio.h>
#include <vector>
using namespace std;

int R, C, T;
int sum = 0;
vector<int> air_cleaner;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void printRoom(vector<vector<int>> &room){
    printf("\n");
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            printf("%d ", room[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
}

bool outOfRange(int r, int c){
    if(r < 0 || r >= R || c < 0 || c >= C){
        return true;
    }
    return false;
}

void activate(vector<vector<int>> &room){
    for(int i = air_cleaner[0] - 1; i >= 0; i--){
        if(room[i+1][0] == -1){
            sum -= room[i][0];
            continue;
        }
        room[i+1][0] = room[i][0];
    }
    for(int i = 1; i < C; i++){
        room[0][i-1] = room[0][i];
    }
    for(int i = 1; i <= air_cleaner[0]; i++){
        room[i-1][C-1] = room[i][C-1];
    }
    for(int i = C-2; i >= 1; i--){
        room[air_cleaner[0]][i+1] = room[air_cleaner[0]][i];
    }

    room[air_cleaner[0]][1] = 0;

    for(int i = air_cleaner[1] + 1; i < R; i++){
        if(room[i-1][0] == -1){
            sum -= room[i][0];
            continue;
        }
        room[i-1][0] = room[i][0];
    }
    for(int i = 1; i < C; i++){
        room[R-1][i-1] = room[R-1][i];
    }
    for(int i = R-2; i >= air_cleaner[1]; i--){
        room[i+1][C-1] = room[i][C-1];
    }
    for(int i = C-2; i >= 1; i--){
        room[air_cleaner[1]][i+1] = room[air_cleaner[1]][i];
    }

    room[air_cleaner[1]][1] = 0;
}

void diffuse(vector<vector<int>> &room, vector<vector<int>> &tmp_room, int r, int c){
    int cnt = 0;
    int dust = tmp_room[r][c] / 5;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(outOfRange(nr, nc) || tmp_room[nr][nc] == -1){
            continue;
        }

        room[nr][nc] += dust;
        cnt++;
    }

    room[r][c] -= dust * cnt;
}

void solve(vector<vector<int>> &room){
    vector<vector<int>> tmp_room = room;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(tmp_room[i][j] > 0){
                diffuse(room, tmp_room, i, j);
            }
        }    
    }
    //printRoom(room);
    activate(room);
}

int main(){
    scanf("%d %d %d", &R, &C, &T);

    vector<vector<int>> room(R, vector<int>(C));

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf("%d", &room[i][j]);

            if(room[i][j] == -1){
                air_cleaner.push_back(i);
            }
            else{
                sum += room[i][j];
            }
        }    
    }

    for(int i = 0; i < T; i++){
        solve(room);

        //printRoom(room);
    }

    printf("%d", sum);

}