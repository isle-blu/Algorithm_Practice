#토마토
import sys
input = sys.stdin.readline

def main():
    m, n, h = map(int, input().split())
    boxes = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
    q = []
    unripe = 0

    for i in range(h):
        for j in range(n):
            for k in range(m):
                if boxes[i][j][k] == 1: q.append((i, j, k))
                if boxes[i][j][k] == 0: unripe += 1

    if unripe == 0:
        print(0)
        return

    dz = [-1, 1, 0, 0, 0, 0] 
    dy = [0 , 0, -1, 1, 0, 0]
    dx = [0 , 0, 0, 0, -1, 1]

    days = 0
    while q:
        next_day = []
        for z, y, x in q:
            for i in range(6):
                nz = z + dz[i]
                ny = y + dy[i]
                nx = x + dx[i]

                if 0 <= nz < h and 0 <= ny < n and 0 <= nx < m and boxes[nz][ny][nx] == 0:
                    next_day.append((nz, ny, nx))
                    boxes[nz][ny][nx] = 1
                    unripe -= 1

    
        q = next_day
        days += 1

        if unripe == 0:
            break

    print(days if unripe == 0 else -1)

main()