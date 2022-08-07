# Program to find sum of alternate polarity odd cubes

def sumFind(num):
    if num <= 0: return 0
    
    term = 0
    termSum = 0
    i = 1
    
    while i <= num:
        term = ((pow(-1, i)) * ((2 * i - 1) ** 3))
        termSum = termSum + term
        
        if i == 1:
            print("- ", end = '')
        
        print(round(abs(term), 6), end = '')
        
        if i != num:
            if ((pow(-1, (i + 1))) * ((2 * (i + 1) - 1) ** 3)) > 0:
                print (' + ', end = '')
            else:
                print (' - ', end = '')
        
        i += 1
    
    return termSum

num = float(input("Enter the number of terms: "))

termSum = sumFind(num)

print(f' = {termSum}')