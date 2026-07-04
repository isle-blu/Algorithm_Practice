#include <stdio.h>
using namespace std;

int main(){
    int x;
    int sum = 0;
    int now = 1;
    scanf("%d", &x);

    while(sum + now < x){
        sum += now;
        now++;
    }

    if(now % 2 == 1){
        int first = now;
        int second = 1;

        first -= x - sum - 1;
        second += x - sum - 1;

        printf("%d/%d", first, second);
    }
    else if(now % 2 == 0){
        int first = 1;
        int second = now;

        first += x - sum - 1;
        second -= x - sum - 1;

        printf("%d/%d", first, second);
    }
}
