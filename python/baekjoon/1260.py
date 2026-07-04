#DFS와 BFS
from collections import deque
import sys

input = sys.stdin.readline

def main():
    N, M, V = map(int, input().split())
    graph = [[] for _ in range(N + 1)]
    

    for _ in range(M):
        row, col = map(int, input().split())
        graph[row].append(col)
        graph[col].append(row)
    
    for i in range(1, N + 1):
        graph[i].sort()
          
    print(" ".join(dfs(graph, V, [False for _ in range( N + 1)], []))) 
    print(" ".join(bfs(graph, V)))

def dfs(graph, now, visited, result):
    visited[now] = True
    result.append(str(now))
    
    for i in graph[now]:
        if not visited[i]:
            dfs(graph, i, visited, result)
    
    return result
    
def bfs(graph, start):
    visited = [False] * (len(graph) + 1)
    visited[start] = True
    queue = deque([start])
    result = []

    while queue:
        now = queue.popleft()
        result.append(str(now))

        for i in graph[now]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

    return result


main()