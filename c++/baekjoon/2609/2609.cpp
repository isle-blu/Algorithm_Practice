#include <stdio.h>
using namespace std;

/*
유클리드 호제법(Euclidean Algorithm)
두 수 a, b가 주어졌을 때,

r = a % b 인 경우

a와 b의 최대공약수 == b 와 r의 최대공약수

최소공배수 = (a * b) / r
*/

int gcd(int num1, int num2){
    if(num2 == 0){
        return num1;
    }

    return gcd(num2, num1 % num2);
}

int lcm(int num1, int num2, int rest){
    return num1 * num2 / rest;
}

int main(){
    int num1, num2, rest;

    scanf("%d %d", &num1, &num2);

    rest = gcd(num1, num2);
    printf("%d\n%d", rest, lcm(num1, num2, rest));

}