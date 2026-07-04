#include <stdio.h>
#include <map>
#include <string>
using namespace std;

int main(){
    int n;
    int max_cnt = 0;
    string ans;
    map<string, int> books;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char tmp[51];
        string book;

        scanf("%s", &tmp);
        book = tmp;

        books[book]++;
    }

    for(auto book : books){
        if(book.second > max_cnt){
            ans = book.first;
            max_cnt = book.second;
        }
    }
    
    printf("%s", ans.c_str());
}