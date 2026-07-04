#include <stdio.h>
#include <queue>
#include <cmath>
using namespace std;

struct Number{
    int num;

    bool operator<(const Number number) const {
        int num1 = abs(this->num);
        int num2 = abs(number.num);

        if(num1 == num2){
            return this->num > number.num;
        }
        return num1 > num2;
    }
};


int main(){
    int n;
    priority_queue<Number> pq;
    
    scanf("%d", &n);

    Number tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp.num);
        if(tmp.num != 0){
            pq.push(tmp);
        }
        else{
            if(pq.empty()){
                printf("%d\n", 0);
            }
            else{
                printf("%d\n", pq.top().num);
                pq.pop();
            }
        }
    }
   
}