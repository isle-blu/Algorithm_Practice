#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(){
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> coordinate(n);

    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        coordinate[i] = {a, b};
    }

    sort(coordinate.begin(), coordinate.end(), cmp);

    for(auto c : coordinate){
        printf("%d %d\n", c.first, c.second);
    }
}