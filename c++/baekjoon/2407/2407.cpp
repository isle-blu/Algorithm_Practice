#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

string arr[102][102];

string add(string num1, string num2){
    string result = "";
    int sum = 0;
    int size1 = num1.size();
    int size2 = num2.size();
    int loop_size = max(size1, size2);

    for(int i = 0; i < loop_size || sum; i++){
        if(size1 > i){
            sum += num1[i] - '0';
        }
        if(size2 > i){
            sum += num2[i] - '0';
        }

        result += sum % 10 + '0';
        sum /= 10;
    }

    return result;
}

string combination(int n, int m){
    if(n == m || m == 0){
        return "1";
    }

    if(arr[n][m] != ""){
        return arr[n][m];
    }

    arr[n][m] = add(combination(n-1, m-1), combination(n-1, m));

    return arr[n][m];    
}


int main(){ 
    int n, m;
    scanf("%d %d", &n, &m);

    combination(n, m);

    for(int i = arr[n][m].size()-1; i >= 0; i--){
        printf("%c", arr[n][m][i]);    
    }
}

// 10       45        120
// 9        36 