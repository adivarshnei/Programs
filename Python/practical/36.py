# Program to print square pattern using numbers row wise inverted

def patternPrint(rows):
    for i in range(rows):
        for j in range(rows):
            print(f"{rows - i}\t", end = '')
        print()
        
    return

rows = int(input("Enter the number of rows: "))

patternPrint(rows)