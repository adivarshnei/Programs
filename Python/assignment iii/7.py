# Program to print all strong numbers between 1 and n

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

def strongList(num):
    strng = []
    
    for i in range(1, num + 1):
        if strongChk(i) == True:
            strng.append(i)
    
    return strng

def printList(entList):
    for i in range(len(entList)):
        print(f"{entList[i]}", end = ' ')

num = int(input("Enter the number: "))

print(f"Strong numbers between 1 and {num} are: ", end = '')
printList(strongList(num))