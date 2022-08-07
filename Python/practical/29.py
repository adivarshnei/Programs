# Program to find sum of factorials

import math

def sumFind(num):
    if num <= 0: return 0
    
    termSum = 0
    
    for i in range(1, num + 1):
        termSum = termSum + (i / math.factorial(i))
        
        print(f"{round(i / math.factorial(i), 6)}", end = '')
        
        if i != num:
            print (' + ', end = '')
            
    return termSum

num = 7

termSum = sumFind(num)

print(f' = {round(termSum, 6)}')