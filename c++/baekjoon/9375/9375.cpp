#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int t, n, ans;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        ans = 1;
        unordered_map<string, int> clothes;

        for(int j = 0; j < n; j++){
            char cloth[20];
            char wear[20];
            scanf(" %s", &cloth);
            scanf(" %s", &wear);
            clothes[wear]++;
        }

        for(auto c : clothes){
            ans *= c.second + 1;
        }

        printf("%d\n", --ans);
    }
}