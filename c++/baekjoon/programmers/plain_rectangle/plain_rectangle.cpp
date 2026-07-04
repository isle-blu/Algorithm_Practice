#include <algorithm>
using namespace std;

long long getGcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    
    return getGcd(b, a%b);
}

long long solution(int w,int h) {
    long long answer = (long long)w * h;
    long long gcd = getGcd(w, h);
    
    answer -= (long long)w + h - gcd;
    
    return answer;
}