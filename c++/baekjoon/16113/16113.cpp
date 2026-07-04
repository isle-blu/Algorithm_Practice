#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int main(){
    int N, size;
    scanf("%d", &N);

    size = N/5;
    vector<vector<char>> signal(5, vector<char>(size));
    string ans;
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < size; j++){
            scanf(" %c", &signal[i][j]);
        }
    }

    int now = 0;
    while(now < size){
        if(signal[0][now] == '.'){
            now++;
            continue;
        }

        if(now + 1 == size || now + 2 == size){
            ans += '1';
            break;
        }
        else if(signal[0][now+1] == '.'){
            if(signal[3][now] == '#'){
                ans += '1';
                now += 2;
                continue;
            }
            else{
                ans += '4';
            }
        }
        else{
            if(signal[1][now] == '.'){
                if(signal[3][now] == '#'){
                    ans += '2';
                }
                else{
                    if(signal[4][now] == '#'){
                        ans += '3';
                    }
                    else{
                        ans += '7';
                    }
                    
                }
            }
            else if(signal[1][now+2] == '.'){
                if(signal[3][now] == '#'){
                    ans += '6';
                }
                else{
                    ans += '5';
                }
            }
            else{
                if(signal[2][now+1] == '.'){
                    ans += '0';
                }
                else{
                    if(signal[3][now] == '.'){
                        ans += '9';
                    }
                    else{
                        ans += '8';
                    }
                }
            }
        }

        now += 3;
    }

    printf("%s", ans.c_str());
}

/*
###.###
..#.#.#
..#.#.#
..#.#.#
..#.###

#...#
#...#
#...#
#...#
#...#

*/
