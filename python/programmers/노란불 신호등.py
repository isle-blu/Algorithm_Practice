# 노란불 신호등

import math

def solution(signals):
    answer = 0
    n = len(signals)
    size = []
    
    for signal in signals:
        size.append(signal[0] + signal[1] + signal[2])
    
    lcm = get_lcm(size[0], size[1])
    
    for i in range(2, n):
        lcm = get_lcm(lcm, size[i])
    
    for i in range(1, lcm + 1):
        cnt = 0
        
        for j in range(n):
            if signals[j][0] < i % size[j] <= signals[j][0] + signals[j][1]:
                cnt += 1
        
        if cnt == n:
            answer = i
            break
        
    if answer == 0: return -1
    
    return answer

def get_lcm(a, b):
    return a * b // math.gcd(a, b)