#1, 2, 3 더하기
import sys
input = sys.stdin.readline

def main():
    T = int(input())
    result = [0] * T
    
    for i in range(T):
        n = int(input())
        find_case(n, n, result, i)
    
    sys.stdout.write('\n'.join(map(str, result)))

def find_case(n, rest, result, idx):
    if rest == 0:
        result[idx] += 1
        return
    
    for i in range(1, 4):
        if i <= rest:
            find_case(n, rest - i, result, idx)

main()