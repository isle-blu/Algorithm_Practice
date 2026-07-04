#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n, p;
    int ans = 0;
    scanf("%d %d", &n, &p);

    vector<vector<int>> melody(7, vector<int>(1, 0));

    for(int i = 0; i < n; i++){
        int line;
        int fret;

        scanf("%d %d", &line, &fret);

        while(fret < melody[line].back()){
            melody[line].pop_back();
            ans++;
        }

        if(fret > melody[line].back()){
            melody[line].push_back(fret);
            ans++;
        }
    }

    printf("%d", ans);
}