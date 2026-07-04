#색종이 만들기
import sys
input = sys.stdin.readline

paper = []
answer = [0, 0] #[white, blue]

def main():
    global paper 

    n = int(input())
    paper = [list(map(int, input().split())) for _ in range(n)]

    recursion(n, 0, 0)

    sys.stdout.write('\n'.join(map(str, answer)))


def check_color(size, r, c):
    color = paper[r][c]

    for i in range(size):
        for j in range(size):
            if color != paper[r + i][c + j]:
                return False

    global answer
    answer[color] += 1

    return True
    
def recursion(size, r, c):
    if not check_color(size, r, c):
        next = size // 2
        recursion(next, r, c)
        recursion(next, r + next, c)
        recursion(next, r, c + next)
        recursion(next, r + next, c + next)

main()