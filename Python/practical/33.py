# Program to print square pattern using numbers column wise

def patternPrint(rows):
    for i in range(rows):
        for j in range(rows):
            print(f"{j + 1}\t", end = '')
        print()
        
    return

rows = int(input("Enter the number of rows: "))

patternPrint(rows)