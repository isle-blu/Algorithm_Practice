#include <stdio.h>
#include <stack>
using namespace std;

int main(){
    int h, w;
    int max_height = 0;
    int ans = 0;
    stack<int> height;

    scanf("%d %d", &h, &w);

    for(int i = 0; i < w; i++){
        scanf("%d", &h);

        if(height.empty()){
            if(h != 0){
                height.push(h);
                max_height = h;
            }
            continue;
        }
        
        if(max_height > h){
            height.push(h);
        }
        else{
            while(!height.empty()){
                ans += max_height - height.top();
                height.pop();
            }
            max_height = h;
            height.push(h);
        }
    }

    if(!height.empty()){
        int before = height.top();
        height.pop();
        while(!height.empty()){
            if(height.top() < before){
                ans += before - height.top();
            }
            else{
                before = height.top();
            }
        
            height.pop();
        }
    }

    printf("%d", ans);

}