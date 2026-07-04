word = input()
list = [-1 for i in range(26)]

for i in range(len(word)) :
    char = ord(word[i]);
    now = char - ord('a')

    if(list[now] == -1) :
        list[now] = i

print(*list)