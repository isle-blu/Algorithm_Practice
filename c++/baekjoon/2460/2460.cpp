#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int max_num = 0;
    int people = 0;
    int up, down;

    for(int i = 0; i < 10; i++){
        scanf("%d %d", &down, &up);

        people += up - down;
        max_num = max(max_num, people);
    }

    printf("%d", max_num);
}