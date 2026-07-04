#include <stdio.h>
using namespace std;

int main(){
    int N, answer = 0;
    scanf("%d", &N);

    int result;
    int score = 1;
    for(int i = 0; i < N; i++){
        scanf("%d", &result);
        if(result == 1){
            answer += score;
            score++;
        }
        else{
            score = 1; 
        }
    }

    printf("%d", answer);
}