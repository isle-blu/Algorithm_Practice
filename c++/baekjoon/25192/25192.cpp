#include <stdio.h>
#include <unordered_set>
#include <string>
using namespace std;

int main(){
    int n;
    int ans = 0;
    unordered_set<string> users;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char tmp[21];
        string name;
        scanf("%s", &tmp);
        name = tmp;

        if(name == "ENTER"){
            users.clear();
        }
        else if(users.find(name) == users.end()){
            users.insert(name);
            ans++;
        }
    }

    printf("%d", ans);
}