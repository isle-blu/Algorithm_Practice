#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int tmp;
        scanf("%d", &tmp);

        int ans = 0;
        while(true){
            tmp /= 5;
            ans += tmp;

            if(tmp < 5){
                break;
            }
        }

        printf("%d\n", ans);
    }
}