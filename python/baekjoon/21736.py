#헌내기는 친구가 필요해
from collections import deque
import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    campus = [input() for _ in range(n)]
    start = find_start(campus, n, m)
    
    ans = bfs(campus, n, m, start)

    if ans == 0:
        print("TT")
        return
    
    print(ans)
    

def find_start(campus, n, m):
    for i in range(n):
        for j in range(m):
            if campus[i][j] == 'I':
                return (i, j) 

def bfs(campus, n, m, start):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    queue = deque([start])
    visited = [[False] * m for _ in range(n)]
    visited[start[0]][start[1]] = True
    ans = 0

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            now_x = x + dx[i]
            now_y = y + dy[i]

            if 0 <= now_x < n and 0 <= now_y < m:
                if not visited[now_x][now_y] and campus[now_x][now_y] != 'X':
                    if campus[now_x][now_y] == 'P': 
                        ans += 1

                    queue.append((now_x, now_y))
                    visited[now_x][now_y] = True


    return ans
                
main()