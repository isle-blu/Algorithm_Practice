# 조이스틱

def solution(name):
    answer = 0
    size = len(name)
    A = ord("A")
    Z = ord("Z")
    cnt = 0
    
    for n in name:        
        curr = ord(n)
        answer += min(curr - A, Z - curr + 1)
    
    if name == "A" * size:
        return answer
    
    min_move = size - 1
    for i in range(size - 1):
        if name[i] == "A":
            continue
        
        back = 0
        for j in range(i + 1, size):
            if name[j] == "A":
                continue
                
            back = size - j
            break
    
        min_move = min(min_move, i * 2 + back, back * 2 + i)
        
    answer += min_move
    
    return answer