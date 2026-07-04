#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> students;

bool cmp(vector<int> a, vector<int> b){
    if(a[1] != b[1]){
        return a[1] > b[1];
    }
    else if(a[2] != b[2]){
        return a[2] < b[2];
    }
    else if(a[3] != b[3]){
        return a[3] > b[3];
    }
    
    return students[a[0]] < students[b[0]];
}

int main(){
    int N;
    scanf("%d", &N);
    
    vector<vector<int>> results(N, vector<int>(4));

    char tmp[11];
    for(int i = 0; i < N; i++){
        scanf(" %s", tmp);
        students.push_back(tmp);

        results[i][0] = i;
        for(int j = 1; j < 4; j++){
            scanf("%d", &results[i][j]);    
        }
    }

    sort(results.begin(), results.end(), cmp);

    for(int i = 0; i < N; i++){
        strcpy(tmp, students[results[i][0]].c_str());
        
        printf("%s\n", tmp);
    }
   
}