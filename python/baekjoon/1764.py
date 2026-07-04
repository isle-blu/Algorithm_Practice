#듣보잡
from collections import Counter
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
people = [input().strip() for _ in range(n + m)]
counts = Counter(people)
twice = [item for item, count in counts.items() if count == 2]
twice.sort()

print(len(twice))
sys.stdout.write("\n".join(twice))