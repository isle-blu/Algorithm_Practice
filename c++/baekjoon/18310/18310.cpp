#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    vector<int> vec(N);

    for(int i = 0; i < N; i++){
        scanf("%d", &vec[i]);
    }

    sort(vec.begin(), vec.end());

    printf("%d", vec[(N-1)/2]);
}