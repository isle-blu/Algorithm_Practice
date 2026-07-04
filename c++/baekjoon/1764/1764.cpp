#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    int N, M;
    map<string, int> names;

    scanf("%d %d", &N, &M);

    int size = N + M;
    for(int i = 0; i < size; i++){
        char tmp[21];
        scanf("%s", &tmp);
        string str = tmp;

        names[str]++;
    }

    int cnt = 0;
    vector<string> ans;
    for(auto name : names){
        if(name.second > 1){
            cnt++;
            ans.push_back(name.first);
        }
    }

    printf("%d\n", cnt);
    for(string name : ans){
        printf("%s\n", name.c_str());
    }
}