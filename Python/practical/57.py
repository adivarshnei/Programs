# Program to calculate factorial using functions

def factorial(num):
    if num == 0: return 1
    
    fact = 1
    
    for i in range(2, num + 1):
        fact = fact * i
    
    return fact

num = int(input("Enter the Number: "))

print(f"{num}! = {factorial(num)}")