#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int dir = 0;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, -1, 0, 1};
    int r = 50;
    int c = 50;
    int max_r = 50;
    int min_r = 50;
    int max_c = 50;
    int min_c = 50;
    vector<vector<char>> maze(101, vector<char>(101, 'X'));
    maze[r][c] = '.';
    
    scanf("%d", &n);
    
    char now;
    scanf("%c", &now);
    for(int i = 0; i < n; i++){
        scanf("%c", &now);

        switch (now)
        {
        case 'R':
            dir++;
            if(dir == 4){
                dir = 0;
            }
            break;

        case 'L':
            dir--;
            if(dir == -1){
                dir = 3;
            }
            break;

        case 'F':
            r += dr[dir];
            c += dc[dir];
            maze[r][c] = '.';
            
            max_r = max(r, max_r);
            max_c = max(c, max_c);
            min_r = min(r, min_r);
            min_c = min(c, min_c);

            break;
        }
    }

    for(int i = min_r; i <= max_r; i++){
        for(int j = min_c; j <= max_c; j++){
            if(maze[i][j] == '.'){
                printf(".");
            }
            else{
                printf("#");
            }
        }
        printf("\n");
    }
}