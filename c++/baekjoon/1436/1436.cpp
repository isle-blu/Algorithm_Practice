#include <stdio.h>
#include <string>
using namespace std;

int main(){
    int n;
    int cnt = 1;
    int ans = 666;

    scanf("%d", &n);
    
    while(cnt < n){
        ans++;

        string tmp = to_string(ans);
        if(tmp.find("666") != string::npos){
            cnt++;
        }
    }

    printf("%d", ans);
}