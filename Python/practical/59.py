# Program to check odd/evenness of a number

from enum import Enum

class numType(Enum):
    INVALID = 0
    ODD = 1
    EVEN = 2

def oddEvenChk(num):
    if num < 0:
        return numType.INVALID
    elif num % 2 != 0:
        return numType.ODD
    else:
        return numType.EVEN

num = int(input("Enter the number: "))

if oddEvenChk(num) == numType.INVALID:
    print("Invalid Number")
elif oddEvenChk(num) == numType.ODD:
    print(f"{num} is Odd")
else:
    print(f"{num} is Even")