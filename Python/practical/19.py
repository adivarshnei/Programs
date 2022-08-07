# Program to generate fibonacci sequence

def fibonacci(num):
    if num == 1:
        return 0
    elif num == 2:
        return fibonacci(num - 1) + 1
    else:
        return fibonacci(num - 1) + fibonacci(num - 2)

def fibonacciSum(num):
    fibSum = 0
    
    for i in range(1, num + 1):
        fibSum += fibonacci(i)
    
    return fibSum

num = int(input("Enter the number: "))

print(f"Fibonacci Sequence: ", end = '')

for i in range(1, num + 1):
    print(f"{fibonacci(i)} ", end = '')

print()

print(f"Sum of Fibonacci numbers upto {num} = {fibonacciSum(num)}")