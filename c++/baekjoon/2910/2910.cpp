#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> cnt_m;
map<int, int> idx_m;

bool cmp(int a, int b){
    if(cnt_m[a] == cnt_m[b]){
        return idx_m[a] < idx_m[b];
    }

    return cnt_m[a] > cnt_m[b];
}

int main(){
    int n, c;
    scanf("%d %d", &n, &c);

    vector<int> seq(n);

    for(int i = 0; i < n; i++){
        scanf("%d", &seq[i]);
        if(idx_m.find(seq[i]) == idx_m.end()){
            idx_m[seq[i]] = i;
        }
        cnt_m[seq[i]]++;
    }

    sort(seq.begin(), seq.end(), cmp);

    for(int s : seq){
        printf("%d ", s);
    }
}