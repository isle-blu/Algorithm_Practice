#include <stdio.h>
#include <queue>
using namespace std;

int main(){
    int n;
    queue<int> cards;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        cards.push(i);
    }

    while(cards.size() > 1){
        cards.pop();
        
        int tmp = cards.front();
        cards.pop();
        cards.push(tmp);
    }

    printf("%d", cards.front());
}