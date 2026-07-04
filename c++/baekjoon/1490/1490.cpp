#include <stdio.h>
#include <unordered_set>
#include <queue>
using namespace std;

unordered_set<int> s;

bool check(long long num){
    for(int i : s){
        if(i == 0){
            continue;
        }
        if(num % i != 0){
            return false;
        }
    }

    return true;
}

int main(){ 
    long long n;
    scanf("%lld", &n);

    queue<long long> q;
    q.push(n);

    long long tmp = n;
    while(tmp > 1){
        s.insert(tmp%10);
        tmp /= 10;
    }

    long long num;
    while(!q.empty()){
        num = q.front();
        q.pop();
        if(check(num)){
            break;
        }

        long long new_num = num*10;
        for(int i = 0; i <= 9; i++){
            q.push(new_num+i);
        }
    }

    printf("%lld", num);
}