#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    vector<bool> submit(31, false);

    int tmp;
    for(int i = 0; i < 28; i++){
        scanf("%d", &tmp);
        submit[tmp] = true;
    }

    for(int i = 1; i < 31; i++){
        if(!submit[i]){
            printf("%d\n", i);
        }
    }
}