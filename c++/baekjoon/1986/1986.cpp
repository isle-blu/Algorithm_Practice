// 다음에 다시

#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

int n, m;

int dr[8] = {-1 , -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void move_queen(int r, int c, vector<vector<int>> board){
    for(int i = 0; i < 8; i++){
        int nr = r + dr[i];
        int nr = c + dc[i];
    }
}

int main(){
    scanf("%d %d", &n, &m);

    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<pair<int, int>> queens;
    vector<pair<int, int>> knights;

    int num, tmp1, tmp2;

    scanf("%d", &num);
    queens.push_back({num, 0});

    for(int j = 0; j < num; j++){
        scanf("%d %d", &tmp1, &tmp2);
        board[tmp1][tmp2] = 1;
        queens.push_back({tmp1, tmp2});
    }

    scanf("%d", &num);
    knights.push_back({num, 0});

    for(int j = 0; j < num; j++){
        scanf("%d %d", &tmp1, &tmp2);
        board[tmp1][tmp2] = 2;
        knights.push_back({tmp1, tmp2});
    }

    scanf("%d", &num);

    for(int j = 0; j < num; j++){
        scanf("%d %d", &tmp1, &tmp2);
        board[tmp1][tmp2] = 3;
    }
   
}