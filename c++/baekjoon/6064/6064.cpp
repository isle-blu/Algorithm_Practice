#include <stdio.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    int T, M, N, x, y;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d %d %d %d", &M, &N, &x, &y);

        int loop_size = lcm(M, N);
        bool TF = false;
        for(int j = x; j <= loop_size; j += M){
            int tmp = j % N == 0 ? N : j % N;
            if(tmp == y){
                printf("%d\n", j);
                TF = true;
                break;
            }
        }

        if(!TF){
            printf("-1\n");
        }
    }
}