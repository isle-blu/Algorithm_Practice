#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string ans;

void combination(string str, int idx, int cnt, int size, vector<string> &result){
    if(cnt == 2){
        string now, result_str;
        now = str.substr(idx);
        reverse(now.begin(), now.end());

        result.push_back(now);

        for(string r : result){
            result_str += r;
        }

        ans = min(ans, result_str);
        result.pop_back();

        return;
    }

    for(int i = idx; i < size; i++){
        string now = str.substr(idx, i-idx+1);
        reverse(now.begin(), now.end());
        result.push_back(now);

        combination(str, i+1, cnt+1, size, result);

        result.pop_back();
    }
}


int main(){
    char arr[51];
    string str;
    vector<string> vec;

    scanf("%s", &arr);
    str = arr;

    ans = str;
    reverse(ans.begin(), ans.end());
    combination(str, 0, 0, str.size()-1, vec);

    printf("%s", ans.c_str());
}
