#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

struct Music{
    int time;
    string title;
    string melody;
};

int getTime(string start, string end){
    int result_time;
    int start_hour = stoi(start.substr(0, 2));
    int end_hour = stoi(end.substr(0, 2));
    int start_min = stoi(start.substr(3));
    int end_min = stoi(end.substr(3));
    
    if(start_hour > end_hour){
        result_time = (24 - start_hour) + end_hour;
    }
    else{
        result_time = end_hour - start_hour;
    }
    
    result_time *= 60;
    
    
    if(start_hour != end_hour && start_min > end_min){
        result_time -= start_min - end_min;
    }
    else{
        result_time += end_min - start_min;
    }
    
    
    return result_time;
}

string getMelody(string melody, int time){
    int size = melody.size();
    string result;
    
    for(char m : melody){
        if(m == '#'){
            size--;
        }
    }
    
    while(time >= size){
        result += melody;    
        time -= size;
    }
    
    if(time > 0){
        int idx = 0;
        for(int i = 0; i < time; i++){
            result += melody[idx];
            
            if(melody[idx] == '#'){
                result += '#';
                idx++;
            }
            idx++;
        }
    }
    
    return result;
    
}


vector<Music> makeFull(vector<string> &musicinfos){
    vector<Music> fullMelody;
    
    for(string str : musicinfos){
        Music music;
        int idx;
        int before_idx;
        string start;
        string end;
        
        idx = str.find(",");
        start = str.substr(0, idx);

        before_idx = idx+1;
        idx = str.find(",", before_idx);
        end = str.substr(before_idx, idx-before_idx);
        
        music.time = getTime(start, end);
        
        before_idx = idx+1;
        idx = str.find(",", before_idx);
        music.title = str.substr(before_idx, idx-before_idx);
        
        before_idx = idx+1;
        music.melody = getMelody(str.substr(before_idx), music.time);
        
        fullMelody.push_back(music);
    }
    
    return fullMelody;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int max_time = 0;
    int size = m.size();
    vector<Music> fullMelody = makeFull(musicinfos);
    
    for(Music now : fullMelody){
        int now_size = now.melody.size();
        int idx = now.melody.find(m);
        while(idx != string::npos){
            if(idx+size == now_size || now.melody[idx+size] != '#'){
                if(max_time < now.time){
                    max_time = now.time;
                    answer = now.title;
                }
                break;
            }
            
            idx = now.melody.find(m, idx+1);
        }    
    }
    
    
    return answer;
}

int main(){
    string m = 	"DF";
    vector<string> vec = {"6:20,6:50,TEST,DDF"};

    cout << solution(m, vec) << endl;
}