# 체육복

def solution(n, lost, reserve):
    l_s = set(lost)
    r_s = set(reserve)
    inter = l_s & r_s
    
    l_s = l_s - inter
    r_s = r_s - inter
    
    n -= len(l_s)
    
    for i in l_s:
        if (i - 1) in r_s:
            n += 1
            r_s.remove(i - 1)
        elif (i + 1) in r_s:
            n += 1
            r_s.remove(i + 1)
    
    return n