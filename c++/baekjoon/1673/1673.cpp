#include <stdio.h>
using namespace std;

int main(){
    long long n, k;

    while(scanf("%lld %lld", &n, &k) != EOF){
        long long cnt = n;
        long long stamp = n;
    
        while(stamp >= k){
            cnt += stamp/k;
            stamp = stamp%k + stamp/k;
        }

        printf("%d\n", cnt);
    }
}