# Program to find sum of factorials

import math

def sumFind(num):
    if num <= 0: return 0
    
    termSum = 0
    
    for i in range(1, num + 1):
        termSum = termSum + math.factorial(i)
        
        print(f"{math.factorial(i)}", end = '')
        
        if i != num:
            print (' + ', end = '')
            
    return termSum

num = int(input("Enter the number of terms: "))

termSum = sumFind(num)

print(f' = {termSum}')