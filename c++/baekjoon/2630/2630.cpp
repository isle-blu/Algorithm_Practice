#include <stdio.h>
#include <vector>
using namespace std;

int ans[2] = {0, 0};

void check(int size, vector<vector<int>> &paper, int r, int c, int now){
    int check_size1 = r + size;
    int check_size2 = c + size;
    vector<vector<int>> tmp_paper = paper;

    for(int i = r; i < check_size1; i++){
        for(int j = c; j < check_size2; j++){
            if(paper[i][j] != now){
                return;
            }
            tmp_paper[i][j] = -1;
        }   
    }

    paper = tmp_paper;
    ans[now]++;
}


int main(){
    int n;

    scanf("%d", &n);

    vector<vector<int>> paper(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &paper[i][j]);
        }
    }

    int size = n;
    while(size > 0){
        for(int i = 0; i < n; i += size){
            for(int j = 0; j < n; j += size){
                if(paper[i][j] != -1){
                    check(size, paper, i, j, paper[i][j]);
                }
            }
        }
        
        size /= 2;
    }

    printf("%d\n%d", ans[0], ans[1]);
} 