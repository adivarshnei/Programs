# Program to calculate factorial using recursion

def factorial(num):
    if num >= 1:
        return num * factorial(num - 1)
    else:
        return 1

num = int(input("Enter the number: "))

print(f"{num}! = {factorial(num)}")