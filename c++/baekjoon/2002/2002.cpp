#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    int ans = 0;
    unordered_map<string, int> cars; 

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char tmp[9];
        string car;

        scanf("%s", &tmp);
        car = tmp;

        cars[tmp] = i;
    }

    vector<string> end(n);

    for(int i = 0; i < n; i++){
        char tmp[9];
        string car;

        scanf("%s", &tmp);
        car = tmp;

        end[i] = car;
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(cars[end[i]] > cars[end[j]]){
                ans++;
                break;
            }
        }
    }

    printf("%d", ans);
}