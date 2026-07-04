#include <stdio.h>
#include <vector>
using namespace std;

float factorial(int a){
    float num = 1;

    for(int i = 1; i <= a; i++){
        num *= i;
    }

    return num;
}

float combianation(int a, int b){
    return factorial(a) / (factorial(b)*factorial(a-b));
}

int main(){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    float ans = combianation(N, M);
    
}