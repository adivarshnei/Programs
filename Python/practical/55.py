# Program to implement simple calculator

from enum import Enum

class zeroErr(Enum):
    VAL1 = 1
    VAL2 = 2
    NONE = 3

def addn(val1, val2):
    return val1 + val2

def subt(val1, val2):
    return val1 - val2, val2 - val1

def mult(val1, val2):
    return val1 * val2

def divs(val1, val2, zeroChk):
    if zeroChk == zeroErr.VAL1:
        return val1 / val2
    elif zeroChk == zeroErr.VAL2:
        return val2/ val1
    
    return val1 / val2, val2 / val1

(val1, val2) = map(int, input("Enter the two values: ").split())

print("1. Addition")
print("2. Subtraction")
print("3. Multiplication")
print("4. Division")
choice = int(input("Enter choice: "))

if choice == 1:
    result = addn(val1, val2)
    
    print(f"{val1} + {val2} = {result}")
elif choice == 2:
    result, altResult = subt(val1, val2)
    
    print(f"{val1} - {val2} = {result}")
    print(f"{val2} - {val1} = {altResult}")
elif choice == 3:
    result = mult(val1, val2)
    
    print(f"{val1} * {val2} = {result}")
elif choice == 4:
    if val1 == 0 and val2 == 0:
        print("Operation Invalid")
    elif val1 == 0:
        result = divs(val1, val2, zeroErr.VAL1)
        print(f"{val1} / {val2} = {result}")
    elif val2 == 0:
        result = divs(val1, val2, zeroErr.VAL2)
        print(f"{val2} / {val1} = {result}")
    else:
        result, altResult = divs(val1, val2, zeroErr.NONE)
        print(f"{val1} / {val2} = {result}")
        print(f"{val2} / {val1} = {altResult}")