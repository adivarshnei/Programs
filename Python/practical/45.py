# Program to print right side triangle pattern using alternate 1's and 0's

def patternPrint(rows):
    num = 1
    
    for i in range(rows):
        if i % 2 == 0:
            num = 1
        else:
            num = 0
        
        for j in range(i + 1):
            if num % 2 == 0:
                print(f"{num}\t", end = '')
                num = num + 1
            else:
                print(f"{num}\t", end = '')
                num = num - 1
                
        print()
        
    return

rows = int(input("Enter the number of rows: "))

patternPrint(rows)