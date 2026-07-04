#include <stdio.h>
#include <string>
using namespace std;

pair<int, int> dfs(string str, int idx){
    if(idx + 1 == str.size()){
        return {0, idx};
    }
    
    if(str[idx] == '('){
        if(str[++idx] == ')'){
            return {2, idx};
        }
        else{
            pair<int, int> result = {0, idx}; 
            
            while (str[result.second] != ')')
            {
                pair<int, int> tmp = dfs(str, result.second);
                if(tmp.first == 0){
                    return {0, str.size()};
                }

                result.first += tmp.first;
                result.second = tmp.second + 1;
                
            }
            
            return {2 * result.first, result.second};
        }
    }
    if(str[idx] == '['){
        if(str[++idx] == ']'){
            return {3, idx};
        }
        else{
            pair<int, int> result = {0, idx}; 
            
            while (str[result.second] != ']')
            {
                pair<int, int> tmp = dfs(str, result.second);
                if(tmp.first == 0){
                    return {0, str.size()};
                }
                result.first += tmp.first;
                result.second = tmp.second + 1;
            }
            
            return {3 * result.first, result.second};
        }
    }
    else{
        return {0, str.size()};
    }
}


int main(){
    string str;
    int ans = 0;

    char tmp[31];

    scanf("%s", &tmp);
    str = tmp;

    for(int i = 0; i < str.size(); i++){
        pair<int, int> result = dfs(str, i);
        if(result.first == 0){
            ans = 0;
            break;
        }

        ans += result.first;
        i = result.second;
    }

    printf("%d", ans);
}