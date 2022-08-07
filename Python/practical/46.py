# Program to print all primes <= a given number

def primeChk(num):
    if num <= 1: return 2
    
    primeFlag = 0
    
    for i in range(2, int((num / 2)) + 1):
        if num % i == 0:
            primeFlag = 1
            break
    
    return primeFlag

limit = int(input("Enter the limit: "))

print(f"Primes below {limit}: ")

for i in range(2, limit + 1):
    if primeChk(i) == 0:
        print(f"{i}\t", end = '')
