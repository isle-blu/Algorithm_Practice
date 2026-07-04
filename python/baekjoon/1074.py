import sys

def recursion(n, r, c, result):
    if n == 0:
        return result

    size = 2 ** (n - 1)

    if r < size:
        if  c < size:
            return recursion(n - 1, r, c, result)
        return recursion(n - 1, r, c - size, result + size ** 2)
    
    if c < size:
        return recursion(n - 1, r - size, c, result + (size ** 2) * 2 )

    return recursion(n - 1, r - size, c - size, result + (size ** 2) * 3 )


n, r, c = map(int, sys.stdin.readline().split())
print(recursion(n, r, c, 0))
