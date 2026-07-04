#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

bool cmp(vector<int> a, vector<int> b){
    if(a[1] == b[1]){
        if(a[2] == b[2]){
            if(a[3] == b[3] && a[0] == K){
                return true;
            }
            
            return a[3] > b[3];

        }
        return a[2] > b[2];
    }
    return a[1] > b[1];
}

int main(){
    scanf("%d %d", &N, &K);

    vector<vector<int>> countries(N);

    for(int i = 0; i < N; i++){
        vector<int> tmp(4);
        scanf("%d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);

        countries[i] = tmp;
    }

    sort(countries.begin(), countries.end(), cmp);

    for(int i = 0; i < N; i++){
        if(countries[i][0] == K){
            printf("%d", i+1);
            return 0;
        }
    }
}