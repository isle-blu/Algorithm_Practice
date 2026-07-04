// not solved
#include <stdio.h>
#include <vector>
using namespace std;

int ans = 0;
int n;

void solve(vector<vector<bool>> &check, int cnt){
    if(cnt == n){
        ans++;
        return;
    }

    vector<vector<bool>> tmp_check = check;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(check[i][j]){
                tmp_check[i][j] = false;

                for(int k = 0; k < n; k++){
                    tmp_check[k][j] = false;
                }

                for(int k = 0; k < n; k++){
                    tmp_check[i][k] = false;
                }


                int k = i+1;
                int l = j+1;
                while(k < n && l < n){
                    tmp_check[k][l] = false;
                    k++;
                    l++;
                }

                k = i-1;
                l = j+1;
                while(k >= 0 && l < n){
                    tmp_check[k][l] = false;
                    k--;
                    l++;
                }

                k = i+1;
                l = j-1;
                while(k < n && l >= 0){
                    tmp_check[k][l] = false;
                    k++;
                    l--;
                }

                k = i-1;
                l = j-1;
                while(k >= 0 && l >= 0){
                    tmp_check[k][l] = false;
                    k--;
                    l--;
                }

                solve(tmp_check, cnt+1);
            }
        }
    }
}

int main(){
    scanf("%d", &n);

    vector<vector<bool>> check(n, vector<bool>(n, true));

    solve(check, 0);

    printf("%d", ans);
}