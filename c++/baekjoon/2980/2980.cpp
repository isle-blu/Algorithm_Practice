#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int N, L;
    scanf("%d %d", &N, &L);

    vector<vector<int>> lights;

    for(int i = 0; i < N; i++){
        vector<int> tmp(3);
        scanf("%d %d %d", &tmp[0], &tmp[1], &tmp[2]);
        lights.push_back(tmp);
    }

    int time = 0;
    int now = 0;

    for(int i = 0; i < N; i++){        
        time += lights[i][0] - now;
        now = lights[i][0];
        
        int light = time % (lights[i][1] + lights[i][2]);

        if(light < lights[i][1]){
            time += lights[i][1] - light;
        }
    }

    time += L - now;

    printf("%d", time);

}