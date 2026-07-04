#단어 정렬
import sys
input = sys.stdin.readline

N = int(input())
s = {input().strip() for _ in range(N)}
words = sorted(s, key=lambda x: (len(x), x))

print(*words, sep='\n')