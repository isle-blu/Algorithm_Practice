def solution(n, times):
    answer = 0

    times.sort(reverse=True); 
    
    lo = 1
    hi = times[0] * n 
    
    while lo < hi:
        mid = (lo + hi) // 2  
        
        
        if check(n, times, mid):
            hi = mid 
            answer = mid 
        else:
            lo = mid + 1 
        
    return answer


def check(n, times, mid):
    cnt = 0
    
    for t in times: 
        cnt += mid // t 
    
        if cnt >= n:
            return True
    
    return False