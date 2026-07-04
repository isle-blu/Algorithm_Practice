#토마토
from collections import deque
import sys
input = sys.stdin.readline

def solve():
    m, n = map(int, input().split())
    box = []
    queue = deque()
    unripe = 0

    for i in range(n):
        now = list(map(int, input().split()))
        for j in range(m):
            if now[j] == 1:
                queue.append((i, j, 0))
            elif now[j] == 0:
                unripe += 1
        box.append(now)

    print(bfs(box, m, n, queue, unripe))

    
def bfs(box, m, n, queue, unripe):
    if unripe == 0:
        return 0

    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]
    result = 0

    while queue:
        r, c, cnt = queue.popleft()
        result = cnt

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if 0 <= nr < n and 0 <= nc < m and box[nr][nc] == 0:
                unripe -= 1
                queue.append((nr, nc, cnt + 1))
                box[nr][nc] = 1

    return result if unripe == 0 else -1

solve()