// 실패
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

unordered_map<string, vector<int>> info_map;
vector<int> answer;

void split(vector<string> &info){
    for(string i : info){
        int len = i.length();
        int score_idx = i.rfind(" ");
        string now_info = i.substr(0, score_idx+1);
        string score_str = i.substr(score_idx);




        info_map[now_info].push_back(atoi(score_str.c_str()));
    }
}

void query_split(string q){
    string result;
    string cutline_str;
    
    stringstream stream(q);
    int idx = 0;
    string tmp;
    while(stream >> tmp){
        if(tmp == "and"){
            continue;
        }
        
        if(idx < 4){
            result += tmp;      
            idx++;
        }
        else{
            cutline_str = tmp;
        }
    }
    
    int cutline = atoi(cutline_str.c_str());
    int cnt = 0;
    for(int score : info_map[result]){
        if(score >= cutline){
            cnt++;
        }
    }
    
    answer.push_back(cnt);   
}

vector<int> solution(vector<string> info, vector<string> query) {
    split(info);
    
    for(auto q : query){
        query_split(q);
    }
    
    
    return answer;
}

int main(){
    vector<string> info = {"java backidx junior pizza 150","python frontidx senior chicken 210","python frontidx senior chicken 150","cpp backidx senior pizza 260","java backidx junior chicken 80","python backidx senior chicken 50"};
    vector<string> query = {"java and backidx and junior and pizza 100","python and frontidx and senior and chicken 200","cpp and - and senior and pizza 250","- and backidx and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    vector<int> answer = solution(info, query);

    for(int a : answer){
        printf("%d ", a);
    }
}