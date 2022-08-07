# Program to find prime factors

import math

def primeChk(num):
    flag = True
    
    for i in range(2, int(math.sqrt(num))):
        if num % i == 0:
            flag == False
            break
    
    return flag

def primeFactors(num):
    i = 2
    fact = []

    while num > 1:
        if (num % i == 0) and (primeChk(i) == True):
            fact.append(i)
            num = int(num / i)
            i = 2
        else:
            i += 1
    
    return fact

def printList(entList):
    for i in range(len(entList)):
        print(f"{entList[i]}", end = ' ')

num = int(input("Enter the number: "))

print(f"Prime factors of {num} are: ", end = '')
printList(primeFactors(num))