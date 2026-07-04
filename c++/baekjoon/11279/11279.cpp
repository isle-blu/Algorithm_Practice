#include <stdio.h>
#include <queue>
using namespace std;

int main(){
    int n;
    priority_queue<int, vector<int>, less<int>> pq;
    scanf("%d", &n);

    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);

        if(tmp == 0){
            if(pq.empty()){
                printf("0\n");
            }
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else{
            pq.push(tmp);
        }
    }
}