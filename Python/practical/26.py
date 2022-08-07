# Program to find sum of alternate polarity harmonic series

def sumFind(num):
    if num <= 0: return 0
    
    term = 0
    termSum = 0
    i = 1
    
    while i <= num:
        term = ((pow(-1, (i + 1))) * (1 / (i)))
        termSum = termSum + term
        
        print(round(abs(term), 6), end = '')
        
        if i != num:
            if ((pow(-1, (i + 2))) * (1 / (i + 1))) > 0:
                print (' + ', end = '')
            else:
                print (' - ', end = '')
        
        i += 1
    
    return termSum


num = float(input("Enter the number of terms: "))

termSum = sumFind(num)

print(f' = {termSum}')