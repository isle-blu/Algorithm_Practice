#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int now = 0;
    deque<string> cache; 
    
    
    if(cacheSize == 0){ //캐시 사이즈가 0인 경우
        answer = cities.size() * 5;
    }
    else{     
        for(string city : cities){
            // 대소문자 구분을 없애기 위해, 소문자 -> 대문자
            for(int i = 0; i < city.size(); i++){
                city[i] = toupper(city[i]); 
            }
            
            auto iter = find(cache.begin(), cache.end(), city);
            if(iter == cache.end()){
                answer += 5;
                if(cache.size() == cacheSize){
                    cache.pop_back();
                }
            }
            else{
                answer += 1;
                cache.erase(iter);
            }
        
            cache.push_front(city);
        }
    }
    
    
    return answer;
}