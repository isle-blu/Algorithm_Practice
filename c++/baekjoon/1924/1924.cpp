#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int main(){
    int m, d;
    int cnt;
    scanf("%d %d", &m, &d);

    vector<int> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    for(int i = 1; i < m; i++){
        cnt += month[i];
    }

    cnt += d;

    printf("%s", week[cnt%7].c_str());
}