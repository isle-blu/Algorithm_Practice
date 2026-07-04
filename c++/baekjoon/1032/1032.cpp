#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, size;
    string answer;
    cin >> n >> answer;
    size = answer.size();

    for(int i = 1; i < n; i++){
        string tmp;
        cin >> tmp;

        for(int j = 0; j < size; j++){
            if(answer[j] != tmp[j]){
                answer[j] = '?';
            }
        }
    }

    cout << answer << endl;
}
