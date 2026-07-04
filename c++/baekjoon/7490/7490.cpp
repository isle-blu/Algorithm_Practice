#include <stdio.h>
#include <string>
using namespace std;

void dfs(int result, string str, int cnt, int end_num, int before_num, char before_oper){
    if(cnt > end_num){
        if(result == 0){
            printf("%s\n", str.c_str());
        }
        return;
    }

    int now_num = before_num * 10 + cnt;
    if(before_oper == '+'){
        dfs(result - before_num + now_num, str + ' ' + to_string(cnt), cnt+1, end_num, now_num, '+');
    }
    else{
        dfs(result + before_num - now_num, str + ' ' + to_string(cnt), cnt+1, end_num, now_num, '-');
    }


    dfs(result+cnt, str + '+' + to_string(cnt), cnt+1, end_num, cnt, '+');
    dfs(result-cnt, str + '-' + to_string(cnt), cnt+1, end_num, cnt, '-');
}

int main(){
    int t, now;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &now);

        dfs(1, "1", 2, now, 1, '+');
        printf("\n");
    }
}