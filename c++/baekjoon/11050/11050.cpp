#include <stdio.h>
using namespace std;

int factorial(int num){
    int result = 1;

    for(int i = num; i > 0; i--){
        result *= num--;
    }

    return result;
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);

    if(K < 0 || K > N){
        printf("0");
    }
    else{
        printf("%d", factorial(N) / (factorial(N-K) * factorial(K)));
    }
}