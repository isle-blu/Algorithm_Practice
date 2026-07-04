#include <stdio.h>
#include <vector>
using namespace std;

int max_value = 0;

void dfs(vector<vector<int>> &area, int cnt){

}

int main(){
    int t, m, n, k;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d %d %d", &m, &n, &k);
        
        vector<vector<int>> area(n, vector<int>(n));
        vector<> area(n, vector<int>(n));
        int x, y;

        for(int j = 0; j < k; j++){
            scanf("%d %d", &x, &y);
            area[y][x] = 1;
        }


    }
}