#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> answer;

void dfs(vector<vector<string>> &tickets, vector<bool> &visited, int size, int now, int count, vector<string> &ans){
    if(count == 1){
        if(answer.empty()){
            answer = ans;
            return;
        }
        
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < 3; j++){
                if(answer[i][j] == ans[i][j]){
                    continue;
                }
            
                if(answer[i][j] > ans[i][j]){
                    answer = ans;
                    return;
                }
            }
        }    

        return;
    }
    
    for(int i = 0; i < size; i++){
        if(visited[i]){
            continue;
        }
            
        if(tickets[i][0] == tickets[now][1]){
            ans.push_back(tickets[i][1]);
            visited[i] = true;
            
            dfs(tickets, visited, size, i, count-1, ans);
            
            ans.pop_back();
            visited[i] = false;
        }
    }    
}

vector<string> solution(vector<vector<string>> tickets) {
    int size = tickets.size();
    
    for(int i = 0; i < size; i++){
        if(tickets[i][0] == "ICN"){
            vector<bool> visited(size, false);
            vector<string> ans;
            
            ans.push_back("ICN");
            ans.push_back(tickets[i][1]);
            visited[i] = true;
            
            dfs(tickets, visited, size, i, size, ans);
        }
    }
    
    return answer;
}

int main()
{
    vector<vector<string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
    vector<string> answer = solution(tickets);
    int size = answer.size();
    for (int i = 0; i < size; i++)
    {
        cout << answer[i] << " ";
    }
}