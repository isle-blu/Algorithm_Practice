#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int N;
    double sum = 0;
    scanf("%d", &N);

    vector<int> vec(N);
    map<int, int> M;

    for(int i = 0; i < N; i++){
        scanf("%d", &vec[i]);
        sum += vec[i];
        M[vec[i]]++;
    }

    sort(vec.begin(), vec.end());

    //산술평균
    sum /= N;

    if(sum > -0.5 && sum < 0){
        sum = 0;
    }
    printf("%.0f\n", sum);

    //중앙값
    printf("%d\n", vec[N / 2]);    
    
    //최빈값
    vector<int> max_value;
    int max_cnt = 0;

    for(auto m : M){
        if(m.second == max_cnt){
            max_value.push_back(m.first);
        }
        else if(m.second > max_cnt){
            max_value.clear();
            max_value.push_back(m.first);
            max_cnt = m.second;
        }
    }

    if(max_value.size() > 1){
        printf("%d\n", max_value[1]);    
    }
    else{
        printf("%d\n", max_value[0]);
    }

    //범위
    printf("%d\n", vec[N-1] - vec[0]);

}