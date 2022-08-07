# Program to print square pattern using stars

def patternPrint(rows):
    for i in range(rows):
        for j in range(rows):
            print("*\t", end = '')
        print()
        
    return

rows = int(input("Enter the number of rows: "))

patternPrint(rows)