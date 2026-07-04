#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t, n, m;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d %d", &n, &m);
        
        if(n == m){
            printf("1\n");
            continue;
        }

        int ans = 1;
        int num = 1;
        int check = m-n;
        while(num <= check){
            ans = ans * m / num;
            m--;
            num++;
        }

        printf("%d\n", ans);
    }
}