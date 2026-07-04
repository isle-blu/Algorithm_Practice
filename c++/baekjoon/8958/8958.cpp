#include <stdio.h>
#include <string>
using namespace std;

int main(){
    int T;
    int score_cnt = 1;
    char tmp[81];
    string result;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        int ans = 0;

        scanf("%s", &tmp);
        result = tmp;


        for(char c : result){
            if(c == 'X'){
                score_cnt = 1;
            }
            else{
                ans += score_cnt;
                score_cnt++;
            }
        }

        printf("%d\n", ans);
        score_cnt = 1;
    }
}