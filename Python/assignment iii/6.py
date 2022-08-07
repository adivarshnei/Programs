# Program to find whether number is strong number

import math

def strongChk(num):
    factSum = 0
    temp = num
    
    while temp > 0:
        factSum += math.factorial(int(temp % 10))
        temp = int(temp / 10)
    
    if factSum == num:
        return True
    else:
        return False

num = int(input("Enter the number: "))

if strongChk(num) == True:
    print(f"{num} is a Strong Number")
else:
    print(f"{num} is not a Strong Number")