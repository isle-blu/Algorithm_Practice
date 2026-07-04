#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int N;
    vector<int> times = {300, 60, 10};
    scanf("%d", &N);

    if(N % 10 != 0){
        printf("-1");
        return 0;
    }

    for(int i = 0; i< 3; i++){
        if(N >= times[i]){
            printf("%d ", N/times[i]);
        }
        else{
            printf("0 ");
        }

        N %= times[i];
    }

    return 0;
}