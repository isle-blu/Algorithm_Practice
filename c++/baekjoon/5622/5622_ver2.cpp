#include <stdio.h>
#include <string>
using namespace std;

int main(){
    char word[16];
    string str;
    scanf("%s", &word);

    str = word;

    int ans = 0;
    for(auto s : str){
        int now = s - 'A' + 1;

        if(now <= 3){
            ans += 2;
        }
        else if(now <= 6){
            ans += 3;
        }
        else if(now <= 9){
            ans += 4;
        }
        else if(now <= 12){
            ans += 5;
        }
        else if(now <= 15){
            ans += 6;
        }
        else if(now <= 19){
            ans += 7;
        }
        else if(now <= 22){
            ans += 8;
        }
        else if(now <= 26){
            ans += 9;
        }
    }

    ans += str.size();

    printf("%d", ans);
}