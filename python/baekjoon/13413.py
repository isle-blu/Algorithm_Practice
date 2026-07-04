#오셀로 재배치
import sys

input = sys.stdin.readline

def main():
    T = int(input())
    result = []

    for _ in range(T):
        result.append(solve())
    
    sys.stdout.write('\n'.join(map(str, result)))


def solve():
    result = 0
    N = int(input())
    pieces = input().strip()
    desired = input().strip()
    p_white = 0
    w_white = 0
    diff = 0

    for i in range(N):
        if pieces[i] != desired[i]:
            diff += 1
        
        if pieces[i] == 'W':
            p_white += 1
        if desired[i] == 'W':
            w_white += 1

    result = abs(p_white - w_white)
    result += (diff - result) // 2

    return result

main()