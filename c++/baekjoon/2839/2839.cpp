#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N, num, cnt5, cnt3;
    scanf("%d", &N);

    cnt5 = N / 5;

    while(true){
        if(cnt5 < 0){
            printf("-1");
            return 0;
        }

        int rest = N - 5 * cnt5;

        if(rest % 3 != 0){
            cnt5--;
        }
        else{
            cnt3 = rest / 3;
            break;
        }
    }

    printf("%d", cnt5 + cnt3);
}