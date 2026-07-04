#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> days(100000);

bool check(int mid){
    int cnt = 1;
    int sum = 0;

    for(int i = 0; i < n; i++){
        if(days[i] > mid){
            return false;
        }

        sum += days[i];

        if(sum > mid){
            cnt++;
            sum = 0;
            i--;
        }
    }

    return m >= cnt;
}

int main(){
    int sum = 0;
    int ans = 0;

    scanf("%d %d", &n, &m);
    
    

    for(int i = 0; i < n; i++){
        scanf("%d", &days[i]);
        sum += days[i];
    }

    int start = 0;
    int end = sum;

    while(start <= end){
        int mid = (start + end) / 2;

        if(check(mid)){
            end = mid - 1;
            ans = mid;
        }
        else{
            start = mid + 1;
        }
    }


    printf("%d", ans);
}