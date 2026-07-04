#include <stdio.h>
#include <stack>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    stack<int> bars;

    int bar;
    for(int i = 0; i < n; i++){
        scanf("%d", &bar);

        while(bars.size() > 0 && bars.top() <= bar){
            bars.pop();
        }
        bars.push(bar);
    }

    printf("%d", bars.size());

    return 0;
}