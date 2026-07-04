#include <stdio.h>
#include <unordered_set>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int note, tmp;
        unordered_set<int> s;

        scanf("%d", &note);
        for(int j = 0; j < note; j++){
            scanf("%d", &tmp);
            s.insert(tmp);
        }

        scanf("%d", &note);
        for(int j = 0; j < note; j++){
            scanf("%d", &tmp);
            
            if(s.find(tmp) != s.end()){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
    }
}