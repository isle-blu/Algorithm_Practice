#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    string str;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> str;
        int left = 0;
        int right = str.size()-1;
        int check = 0;
        int tmp_left, tmp_right;

        while(left < right){
            if(str[left] == str[right]){
                left++;
                right--;
                continue;
            }

            if(check == 0 && str[left] == str[right-1]){
                tmp_left = left+1;
                tmp_right = right;
                left++;
                right-=2;
                check = -1;
            }
            else if(check == 0 && str[left+1] == str[right]){
                left+=2;
                right--;
                check = 1;
            }
            else{
                if(check == -1){
                    left = tmp_left;
                    right = tmp_right;
                    check = 1;
                }
                else{
                    check = 2;
                    break;
                }
            }
        }

        if(check == -1){
            check = 1;
        }
        
        cout << check << "\n";
    }
}