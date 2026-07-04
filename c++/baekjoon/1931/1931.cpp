#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int ans = 0;
    vector<pair<int, int>> conference;
    
    scanf("%d", &n);

    int tmp1, tmp2;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &tmp1, &tmp2);
        conference.push_back({tmp2, tmp1});
    }

    sort(conference.begin(), conference.end());

    int time = 0;
    for(int i = 0; i < n; i++){
        if(time <= conference[i].second){
            time = conference[i].first;
            ans++;
        }
    }

    printf("%d", ans);
}