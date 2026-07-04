#듣보잡
from collections import Counter
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
hear = set([input().strip() for _ in range(n)])
see = set([input().strip() for _ in range(m)])
twice = list(hear & see)
twice.sort()

print(len(twice))
sys.stdout.write("\n".join(twice))