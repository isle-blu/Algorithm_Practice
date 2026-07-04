#include <stdio.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        int N, M, now, idx, cnt;
        scanf("%d %d", &N, &M);

        now = M;
        idx = N - 1;
        cnt = 0;

        vector<int> vec(N);

        for(int j = 0;  j < N; j++){
            scanf("%d", &vec[j]);
        }

        deque<int> pq(vec.begin(), vec.end());

        sort(vec.begin(), vec.end());

        while(true){
            if(vec[idx] == pq[0]){
                pq.pop_front();
                idx--;
                cnt++;
                if(M == 0){
                    break;
                }
                M--;
            }
            else{
                pq.push_back(pq.front());
                pq.pop_front();
                M = M == 0 ? pq.size() - 1 : M-1; 
            }
        }

        printf("%d\n", cnt);
    }
}