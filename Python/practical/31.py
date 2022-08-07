# Program to find sum of odd fourth powers

def sumFind(num):
    if num <= 0: return 0
    
    term = 0
    termSum = 0
    i = 1
    
    while i <= num:
        term = ((2 * i - 1) ** 4)
        termSum = termSum + term
        
        print(round(abs(term), 6), end = '')
        
        if i != num:
            print (' + ', end = '')
            
        i += 1
    
    return termSum

num = 100

termSum = sumFind(num)

print(f' = {termSum}')