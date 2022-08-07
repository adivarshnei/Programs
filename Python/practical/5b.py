# Program to swap two numbers without third variable

def numSwap(num1, num2):
    num1 = num1 + num2
    num2 = num1 - num2
    num1 = num1 - num2
    
    return num1, num2

num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))

print(f"Numbers before swapping : {num1}, {num2}")
print(f"Numbers after swapping : {numSwap(num1, num2)[0]}, {numSwap(num1, num2)[1]}")