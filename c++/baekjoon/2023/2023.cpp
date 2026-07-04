#include <stdio.h>
using namespace std;

int n;
void dfs(int now, int cnt){
    if(cnt == n){
        if(now != 1){
            printf("%d\n", now);    
        }
        return;
    }
    
    now *= 10;

    for(int i = 1; i <=9; i++){
        int tmp_now = now + i;
        bool check = true;

        for(int j = 2; j <= tmp_now/2; j++){
            if(tmp_now%j == 0){
                check = false;
                break;
            }
        }

        if(check){
            dfs(tmp_now, cnt+1);
        }
    }
}


int main(){
    scanf("%d", &n);

    int arr[4] = {2, 3, 5, 7};

    for(int a : arr){
        dfs(a, 1);
    }
}