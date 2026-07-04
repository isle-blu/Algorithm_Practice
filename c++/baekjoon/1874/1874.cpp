#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;


int main(){
    int n, num;
    vector<int> seq;
    vector<char> ans;
    stack<int> seq_s;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        seq.push_back(num);
    }

    int idx = 0;
    num = 1;
    while(idx < n){
        if(seq_s.empty()){
            seq_s.push(num);
            ans.push_back('+');
            num++;
        }
        else if(seq[idx] < seq_s.top()){
            printf("NO");
            return 0;
        }
        else if(seq[idx] == seq_s.top()){
            seq_s.pop();
            ans.push_back('-');
            idx++;
        }
        else{
            seq_s.push(num);
            ans.push_back('+');
            num++;
        }
    }

    for(int i = 0; i < ans.size(); i++){
        printf("%c\n", ans[i]);
    }
}