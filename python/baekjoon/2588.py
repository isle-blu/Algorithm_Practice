num1 = int(input())
num2 = int(input())

one = num2 % 10
ten = num2 % 100 // 10
hundread = num2 // 100

print(num1 * one)
print(num1 * ten)
print(num1 * hundread)
print(num1 * num2)
