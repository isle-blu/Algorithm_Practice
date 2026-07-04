#바이러스

import sys
from collections import deque

input = sys.stdin.readline

def main():
    com = int(input())
    pair = int(input())
    graph = [[] for _ in range(com + 1)]
    
    for _ in range(pair):
        c1, c2 = map(int, input().split())
        
        graph[c1].append(c2)
        graph[c2].append(c1)
        
    queue = deque([1])
    visited = [False] * (com + 1)
    visited[1] = True
    cnt = 0
    while queue:
        now = queue.popleft()
        
        for i in graph[now]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
                cnt += 1
    
    print(cnt)

    
main()