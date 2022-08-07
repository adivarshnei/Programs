# Program to Check Prime Numbers

def primeChk(num):
    if num <= 1: return 2
    
    primeFlag = 0
    
    for i in range(2, int((num / 2)) + 1):
        if num % i == 0:
            primeFlag = 1
            break
    
    return primeFlag

num = int(input("Enter the number: "))

primeFlag = primeChk(num)

if primeFlag == 2:
    print(f"{num} is neither prime nor composite")
elif primeFlag == 0:
    print(f"{num} is prime")
else:
    print(f"{num} is composite")
    print(f"Its factors are: ", end = "")
    
    for i in range(1, int(num / 2) + 1):
        if num % i == 0:
            print(f"{i}\t", end = "")