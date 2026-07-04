#쉬운 최단거리
import sys
from collections import deque
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(n)]
    start = find_start(graph, n, m)
    result = solve(graph, n, m, start)

    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1 and result[i][j] == 0: result[i][j] = -1
    
    sys.stdout.write('\n'.join([' '.join(map(str, row)) for row in result]))
    
def find_start(graph, n, m):
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 2: return (i, j, 1)

def solve(graph, n, m, start):
    queue = deque([start])
    visited = [[False] * m for _ in range(n)] 
    result = [[0] * m for _ in range(n)]

    visited[start[0]][start[1]] = True
    while queue:
        i, j, cnt = queue.popleft()

        if i > 0 and not visited[i - 1][j] and graph[i - 1][j] == 1:
            visited[i - 1][j] = True
            result[i - 1][j] = cnt
            queue.append((i - 1, j, cnt + 1))

        if i < n - 1 and not visited[i + 1][j] and graph[i + 1][j] == 1:
            visited[i + 1][j] = True
            result[i + 1][j] = cnt
            queue.append((i + 1, j, cnt + 1))

        if j > 0 and not visited[i][j - 1] and graph[i][j - 1] == 1 :
            visited[i][j - 1] = True
            result[i][j - 1] = cnt
            queue.append((i, j - 1, cnt + 1))

        if j < m - 1 and not visited[i][j + 1] and graph[i][j + 1] == 1:
            visited[i][j + 1] = True
            result[i][j + 1] = cnt
            queue.append((i, j + 1, cnt + 1))
    
    return result
    
main()