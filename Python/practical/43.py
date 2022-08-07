# Program to print upright triangle pattern using numbers

def patternPrint(rows):
    i = 0
    
    while i < rows:
        j = rows - 1
        
        while j > i:
            print("\t", end = '')
            j = j - 1
        
        j = 0
        
        while j < i + 1:
            print(f"{j + 1}\t", end = '')
            j = j + 1
        
        j = j - 1
        
        while j >= 1:
            print(f"{j}\t", end = '')
            j = j - 1
        
        print()
        
        i = i + 1
        
    return

rows = int(input("Enter the number of rows: "))

patternPrint(rows)