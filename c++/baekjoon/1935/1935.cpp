#include <stdio.h>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int N;
    string str;
    stack<double> number;
    unordered_map<char, int> m;

    scanf("%d", &N);
    
    char tmp[101];
    scanf(" %s", &tmp);
    str = tmp;

    char c = 'A';
    for(int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);

        m.insert({c, num});
        c++;
    }


    for(char now : str){
        double num;
        switch (now)
        {
        case '+':
            num = number.top();
            number.pop();

            number.top() += num;
            break;

        case '-':
            num = number.top();
            number.pop();

            number.top() -= num;
            break;

        case '*':
            num = number.top();
            number.pop();

            number.top() *= num;
            break;

        case '/':
            num = number.top();
            number.pop();

            number.top() /= num;
            break;
        
        default:
            number.push(m[now]);

            break;
        }
    }

    printf("%.2lf", number.top());
}