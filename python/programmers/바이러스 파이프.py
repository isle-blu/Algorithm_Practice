# 바이러스 파이프

def solution(n, infection, edges, k):
    answer = 0  
    
    graph = [[[] for _ in range(0, 4)] for _ in range(0, n + 1)] 
    for x, y, pipe in edges:
        graph[x][pipe].append(y)
        graph[y][pipe].append(x)
    
    virus = [False] * (n + 1) # 감염여부 확인
    virus[infection] = True
    
    for i in range(1, 4):
        answer = max(answer, recursion(graph, virus[:], 0, k, 1, n, i))        
    
    return answer

def recursion(graph, virus, idx, k, cnt, n, pipe):
    if idx == k:
        return cnt
    
    
    # bfs
    q = []
    
    for i in range(1, n + 1):
        if virus[i] : q.append(i)
    
    while q:
        next_q = []
        for i in q:
            for j in graph[i][pipe]:
                if not virus[j]:
                    virus[j] = True
                    cnt += 1
                    next_q.append(j)
        
        q = next_q
    
    if cnt == n:
        return cnt
    
    tmp = cnt
    for i in range(1, 4):
        if i == pipe: continue
        
        cnt = max(cnt, recursion(graph, virus[:], idx + 1, k, tmp, n, i))
    
    return cnt
    