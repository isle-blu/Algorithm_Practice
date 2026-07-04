#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N;
    vector<int> letter(53, 0);
    string plain;
    bool TF = true;

    scanf("%d", &N);

    int tmp;
    for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
        letter[tmp]++;
    }

    cin.ignore();
    getline(cin, plain);

    int num;
    for(auto c : plain){
        if(c == ' '){
            if(letter[0] == 0){
                TF = false;
                break;
            }
            letter[0]--;
        }
        else if(c >= 'a'){
            num = c - 'a' + 27;

            if(letter[num] == 0){
                TF = false;
                break;
            }
            letter[num]--;
        }
        else{
            num = c - 'A' + 1;

            if(letter[num] == 0){
                TF = false;
                break;
            }
            letter[num]--;
        }
    }

    if(TF){
        printf("y");
    }
    else{
        printf("n");
    }
}