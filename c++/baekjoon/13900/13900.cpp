#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n;
    long long sum = 0;
    long long ans = 0;

    scanf("%d", &n);
    
    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        scanf("%d", &vec[i]);
        sum += vec[i];
    }

    for(int i = 0; i < n-1; i++){
        sum -= vec[i];
        ans += sum * vec[i];
    }

    printf("%lld", ans);
}