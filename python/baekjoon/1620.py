#나는야 포켓몬 마스터 이다솜

import sys

input = sys.stdin.readline

N, M = map(int, input().split())
pocketmon_list = [0] * (N + 1)
pocketmon_dict = {}

for i in range(1, N+1):
    pocketmon = input().strip()
    pocketmon_list[i] = pocketmon
    pocketmon_dict[pocketmon] = i

result = []
for _ in range(M):
    query = input().strip()
    
    if query.isdigit():
        result.append(pocketmon_list[int(query)])
    else:
        result.append(str(pocketmon_dict[query]))

sys.stdout.write('\n'.join(result))