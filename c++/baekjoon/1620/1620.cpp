#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

int main(){
    int n, m;
    unordered_map<int, string> pocketmon_num; //도감 번호 기준으로 이름 저장
    unordered_map<string, int> pocketmon_name; //이름 기준으로 도감 번호 저장
    unordered_set<char> num = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // 입력이 숫자인지 문자인지 확인하기 위한 set

    scanf("%d %d", &n, &m);

    // 도감 입력
    char tmp[21];
    int idx = 1;
    string s;
    for(int i = 0; i < n; i++){
        scanf(" %s", &tmp);
        s = tmp;
        pocketmon_num[idx] = s;
        pocketmon_name[s] = idx;
        idx++; // 도감번호 증가
    }

    // 도감 번호 출력
    for(int i = 0; i < m; i++){
        scanf(" %s", &tmp);
        s = tmp;

        // 숫자인지 확인
        if(num.find(s[0]) != num.end()){
            int now = atoi(s.c_str()); 
            printf("%s\n", pocketmon_num[now].c_str());
        }
        else{
            printf("%d\n", pocketmon_name[s]);
        }
    }
}
