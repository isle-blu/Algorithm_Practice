#나이순 정렬
import sys

input = sys.stdin.readline

N = int(input())
members = []

for i in range(N):
    age, name = input().split()
    members.append((int(age), name))

members.sort(key=lambda x: x[0])
formatted = [f"{age} {name}" for age, name in members]

print('\n'.join(formatted))