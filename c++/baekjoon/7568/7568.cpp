#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int N;
    scanf("%d", &N);

    vector<vector<int>> people(N, vector<int>(3));

    for(int i = 0; i < N; i++){
        scanf("%d %d", &people[i][0], &people[i][1]);
    }

    for(int i = 0; i < N; i++){
        people[i][2] = 1;
        for(int j = 0; j < N; j++){
            if(i == j){
                continue;
            }

            if(people[i][0] < people[j][0] && people[i][1] < people[j][1]){
                people[i][2]++;
            }
        }
    }

    for(auto p : people){
        printf("%d ", p[2]);
    }

}