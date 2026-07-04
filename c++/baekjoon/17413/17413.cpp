#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string S;
    char tmp[100001];

    scanf("%[^\n]s", &tmp);

    S = tmp;

    string now;
    bool flag  = false;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '<'){
            if(flag){
                printf("%s", now.c_str());
            }
            else{
                reverse(now.begin(), now.end());
                printf("%s", now.c_str());
            }
            
            now = "<";
            flag = true;
        }
        else if(S[i] == '>'){
            now += ">";
            printf("%s", now.c_str());
            flag = false;
            now.clear();
        }
        else if(S[i] == ' ' && !flag){
            reverse(now.begin(), now.end());
            now += " ";
            printf("%s", now.c_str());
            now.clear();
        }
        else{
            now += S[i];
        }
    }

    if(!now.empty()){
        reverse(now.begin(), now.end());
        printf("%s", now.c_str());
    }
}