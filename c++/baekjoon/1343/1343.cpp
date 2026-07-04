#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

int main(){
    char tmp[51];
    string str;
    int size, cnt, start;

    scanf("%s", tmp);

    str = tmp;
    size = str.size();
    cnt = 0;

    for(int i = 0; i < size; i++){
        if(str[i] == 'X'){
            if(cnt == 0){
                start = i;
            }
            cnt++;
        }
        else{
            if(cnt % 2 != 0){
                printf("-1");
                return 0;
            }

            while(cnt >= 4){
                for(int j = start; j < start + 4; j++){
                    str[j] = 'A';
                }

                start += 4;
                cnt -= 4;
            }

            if(cnt == 2){
                str[start++] = 'B';
                str[start] = 'B';
                cnt = 0;
            }
        }
    }

    if(cnt % 2 != 0){
        printf("-1");
        return 0;
    }
    while(cnt >= 4){
        for(int j = start; j < start + 4; j++){
            str[j] = 'A';
        }
        start += 4;
        cnt -= 4;
    }
    if(cnt == 2){
        str[start++] = 'B';
        str[start] = 'B';
    }

    strcpy(tmp, str.c_str());
    printf("%s", tmp);
}