#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    double sum = 0;
    int max_num = 0;
    vector<double> score;

    scanf("%d", &n);

    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        max_num = max(max_num, tmp);
        score.push_back(tmp);
    }

    for(int i = 0;  i < n; i++){
        score[i] = score[i] / max_num * 100;
        sum += score[i];
    }

    printf("%lf", sum/n);
}