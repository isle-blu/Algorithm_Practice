#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int people; // 사람 수
    int party_num; // 파티 수
    int truth_num; // 진실을 아는 사람 수
    int ans; 
    scanf("%d %d\n%d", &people, &party_num, &truth_num);

    vector<vector<int>> party_vec(party_num); // 각 파티별 참여하는 사람
    vector<vector<int>> people_vec(people+1); // 각 사람별 참여하는 파티
    vector<bool> party_visited(party_num, false); // 파티별 체크 여부
    vector<bool> know_truth(people+1, false); // 처음부터 진실을 알고 있던 사람
    queue<int> q; // bfs 응용을 위한 queue
    ans = party_num;

    // 진실을 아는 인원의 경우 true로 저장
    for(int i = 0; i < truth_num; i++){
        int tmp;
        scanf("%d", &tmp);
        know_truth[tmp] = true;
    }

    // 각 파티별 참여하는 사람과, 각 사람별 참여하는 파티 저장
    for(int i = 0; i < party_num; i++){
        int now_num;
        bool TF = false; // 그 파티에 처음부터 진실을 알고있는 인원이 있다면 true
        scanf("%d", &now_num);

        for(int j = 0; j < now_num; j++){
            int tmp;
            scanf("%d", &tmp);
            
            people_vec[tmp].push_back(i);
            party_vec[i].push_back(tmp);

            if(know_truth[tmp]){
                TF = true;
            }
        }

        // 진실을 아는 인원이 있으면 queue에 push
        if(TF){
            q.push(i);
            party_visited[i] = true;
            ans--;
        }
    }

    // bfs 응용
    while(!q.empty()){
        int now = q.front(); // 현재 체크할 파티
        q.pop();

        for(int person : party_vec[now]){ // 파티별 참여한 인원
            for(int party : people_vec[person]){ // 해당 인원이 참여한 파티
                // 아직 체크하지 않은 파티인 경우, 진실을 말하는 파티이므로 ans--, queue에 push
                if(!party_visited[party]){ 
                    q.push(party);
                    party_visited[party] = true;
                    ans--;
                }
            }
        }
    }

    printf("%d", ans);
}