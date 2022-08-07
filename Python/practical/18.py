# Program to find the factorial of a number

def factorial(num):
    if num == 1 or num == 0:
        return 1
    else:
        return num * factorial(num - 1)

num = int(input("Enter a number: "))

print(f"{num}! = {factorial(num)}")