#include <stdio.h>
using namespace std;

int main(){
    int ans = 0, num;
    scanf("%d", &num);

    for(int i = 1; i < num; i++){
        int now = i;
        int sum = i;

        while(now > 0){
            sum += now % 10;
            now /= 10;
        }

        if(sum == num){
            ans = i;
            break;
        }    
        
    }

    printf("%d", ans);
}