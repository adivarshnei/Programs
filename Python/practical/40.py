# Program to print right side triangle pattern using numbers column wise inverted

def patternPrint(rows):
    for i in range(rows):
        for j in range(i + 1):
            print(f"{rows - j}\t", end = '')
        print()
        
    return

rows = int(input("Enter the number of rows: "))

patternPrint(rows)