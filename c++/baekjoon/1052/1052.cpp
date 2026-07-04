#include <stdio.h>
#include <unordered_map>
using namespace std;

int main(){
    int n, k;
    int max_value = 1;
    unordered_map<int, int> pet;

    scanf("%d %d", &n, &k);
    pet[1] = n;

    int cnt = 0;

    while(true){
        int i = 1;
        
        while(pet[i] > 1){
            int next = i*2;

            pet[next] += pet[i] / 2;
            n -= pet[i] / 2;
            pet[i] %= 2;

            i *= 2;
        }

        if(n <= k){
            break;
        }
        
        pet[1]++;
        n++;
        cnt++;
    }
    
    printf("%d", cnt);
}