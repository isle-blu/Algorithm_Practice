#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    string number;
    int ans = 0;
    unordered_map<char, int> cnt;

    scanf("%d", &n);

    number = to_string(n);

    for(auto n : number){
        cnt[n]++;

        if(n == '6' || n == '9'){
            int six_nine = abs(cnt['6'] - cnt['9']);
            six_nine = six_nine / 2 + six_nine % 2 + min(cnt['6'], cnt['9']);

            if(six_nine > ans){
                ans = six_nine;
            }
            
        }
        else if(cnt[n] > ans){
            ans = cnt[n];
        }
    }

    printf("%d", ans);
}