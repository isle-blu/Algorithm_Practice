#유기농 배추
from collections import deque
import sys
input = sys.stdin.readline

def main():
    T = int(input())
    result = [0] * T
    
    for i in range(T):
        M, N, K = map(int, input().split())
        field = [[0] * N for _ in range(M)]
        visited = [[False] * N for _ in range(M)]
        
        for _ in range(K):
            x, y = map(int, input().split())
            field[x][y] = 1
        
        for x in range(M):
            for y in range(N):
                if visited[x][y]:  
                    continue
                
                if field[x][y] == 1:
                    bfs(field, visited, M, N, x, y)
                    result[i] += 1
                    
    sys.stdout.write('\n'.join(map(str, result)))
    
def bfs(field, visited, M, N, x, y):
    queue = deque([(x, y)])
    visited[x][y] = True
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    while queue:
        now_x, now_y = queue.popleft()
        
        for i in range(4):
            next_x = now_x + dx[i]
            next_y = now_y + dy[i]
            
            if next_x < 0 or next_x >= M or next_y < 0 or next_y >= N : 
                continue
            
            if visited[next_x][next_y]:
                continue
                
            if field[next_x][next_y] == 1:
                visited[next_x][next_y] = True
                queue.append((next_x, next_y))

main()