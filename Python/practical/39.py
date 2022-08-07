# Program to print right side triangle pattern using numbers row wise

def patternPrint(rows):
    for i in range(rows):
        for j in range(i + 1):
            print(f"{i + 1}\t", end = '')
        print()
        
    return

rows = int(input("Enter the number of rows: "))

patternPrint(rows)