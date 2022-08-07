# Program to print right side triangle pattern using stars

def patternPrint(rows):
    for i in range(rows):
        for j in range(i + 1):
            print("*\t", end = '')
        print()
        
    return

rows = int(input("Enter the number of rows: "))

patternPrint(rows)