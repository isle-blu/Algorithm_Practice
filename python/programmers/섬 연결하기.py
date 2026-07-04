# 섬 연결하기 - 도움
def solution(n, costs):
    answer = 0
    parent = [i for i in range(n)]
    cnt = 0
    
    costs.sort(key = lambda x: x[2])
    
    for isle1, isle2, cost  in costs: 
        if find_parent(parent, isle1) != find_parent(parent, isle2): 
            answer += cost
            union_parent(parent, isle1, isle2)
            
            if cnt == n - 1:
                break
    
    return answer

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
        
    return parent[x]

def union_parent(parent, isle1, isle2):
    a = find_parent(parent, isle1)
    b = find_parent(parent, isle2)
    
    if a < b:
        parent[b] = a
    else:
        parent[a] = b