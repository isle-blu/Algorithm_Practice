#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int num;
    scanf("%d", &num);

    int seq1 = 0;
    int seq2 = 1;

    for(int i = 2; i <= num; i++){
        if(i % 2 == 0){
            seq1 += seq2;
        }
        else{
            seq2 += seq1;
        }
    }

    printf("%d", num%2 == 0 ? seq1 : seq2);
}