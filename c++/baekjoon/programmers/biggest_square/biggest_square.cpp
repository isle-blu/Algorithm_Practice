#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool outOfRange(int r, int c){
    if(r < 1 || c < 1){
        return true;
    }
    return false;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int size1 = board.size();
    int size2 = board[0].size();
    vector<vector<int>> dp(1000, vector<int>(1000, 0));

    
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(board[i][j] == 1){
                if(!outOfRange(i, j)){
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
                else{
                    dp[i][j] = 1;
                }
                answer = max(dp[i][j] * dp[i][j], answer);
            }
        }
    }
    
    return answer;
}