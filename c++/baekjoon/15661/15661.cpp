#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
int ans = INT_MAX;

void solve(vector<vector<int>> &members, vector<bool> &check){
    vector<int> team1;
    vector<int> team2;

    int power1 = 0;
    int power2 = 0;
    int size, result;

    for(int i = 0; i < N; i++){
        if(check[i]){
            team1.push_back(i);
        }
        else{
            team2.push_back(i);
        }
    }

    size = team1.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            power1 += members[team1[i]][team1[j]];
        }
    }

    size = team2.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            power2 += members[team2[i]][team2[j]];
        }
    }

    result = abs(power1 - power2);

    if(result < ans){
        ans = result;
    }    
}

void make_team(vector<vector<int>> &members, vector<bool> &check, int idx){   
    for(int i = idx; i < N; i++){
        check[i] = true;
        solve(members, check);
        make_team(members, check, i+1);
        check[i] = false;
    }
}

int main(){
    scanf("%d", &N);

    vector<vector<int>> members(N, vector<int>(N));
    vector<bool> check(N, false);

    for(int i = 0; i < N;  i++){
        for(int j = 0;  j < N; j++){
            scanf("%d", &members[i][j]);
        }
    }

    check[0] = true;
    solve(members, check);
    make_team(members, check, 1);

    printf("%d", ans);
}