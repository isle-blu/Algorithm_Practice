# 단속카메라

def solution(routes):
    answer = 1
    routes.sort(key = lambda x: x[0])
    
    now_out = routes[0][1]
    for i in range(1, len(routes)):
        if routes[i][0] > now_out:
            now_out = routes[i][1]
            answer += 1
        elif routes[i][1] < now_out:
            now_out = routes[i][1]
            
    return answer