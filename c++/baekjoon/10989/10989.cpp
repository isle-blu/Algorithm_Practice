#include <stdio.h>
#include <map>
using namespace std;

int main(){
    int n;
    map<int, int> m;

    scanf("%d", &n);

    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);

        m[tmp]++;
    }

    for(auto i : m){
        for(int j = 0; j < i.second; j++){
            printf("%d\n", i.first);
        }
    }
}
