#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    long long M, start, end, ans;
    scanf("%d %lld", &N, &M);

    vector<long long> trees(N);

    for(int i = 0; i < N; i++){
        scanf("%lld", &trees[i]);
        end += trees[i];
    }

    sort(trees.begin(), trees.end());

    start = 0;
    end = trees[N-1];

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long sum = 0;

        for(int i = 0; i < N; i++){
            sum += trees[i] > mid ? trees[i] - mid : 0;
        }

        if(sum < M){
            end = mid - 1;
        }
        else{
            ans = mid;
            start = mid + 1;
        }
    }

    printf("%lld", ans);

    return 0;
}