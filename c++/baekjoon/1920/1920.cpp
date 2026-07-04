#include <stdio.h>
#include <unordered_set>
using namespace std;

int main(){
    int n;
    unordered_set<int> s;
    scanf("%d", &n);

    int tmp;
    for(int i = 0; i< n; i++){
        scanf("%d", &tmp);
        s.insert(tmp);
    }

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        
        if(s.find(tmp) != s.end()){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
}