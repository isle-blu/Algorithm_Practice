num1, num2 = map(str, input().split())
num1 = num1[::-1]
num2 = num2[::-1]

if(num1 > num2) : print(num1)
else : print(num2)