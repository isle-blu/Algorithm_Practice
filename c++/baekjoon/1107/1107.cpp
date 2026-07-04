#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> brocken(10, false);

bool check(string str){
    for(char s : str){
        if(brocken[s-'0']){
            return false;
        }
    }

    return true;
}

int main(){
    int n, m, ans;

    scanf("%d\n%d", &n, &m);

    int tmp;
    for(int i = 0; i < m; i++){
        scanf("%d", &tmp);
        brocken[tmp] = true;
    }

    ans = abs(n - 100);

    for(int i = 0; i <= 1000000; i++){
        string str = to_string(i);
        if(check(str)){
            ans = min(ans, (int)str.size() + abs(n - i));
        }
    }
    
    printf("%d", ans);

}