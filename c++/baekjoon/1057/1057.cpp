#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
    int N, kim, lim;

    scanf("%d %d %d", &N, &kim, &lim);

    int round = 1;
    while(N > 0){
        int tmp_kim = (kim + 1)/2;
        int tmp_lim = (lim + 1)/2;

        if(tmp_kim == tmp_lim){
            break;
        }

        if(N % 2 == 1){
            N /= 2;
            N += 1;
        }
        else{
            N /= 2;
        }

        kim = tmp_kim;
        lim = tmp_lim;
        round++;
    }

    if(N <= 0){
        printf("%d", -1);
    }
    else{
        printf("%d", round);
    }

}