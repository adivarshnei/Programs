# Program to print all ASCII characters with values
def printASCII():
    for i in range(32, 255):
        print(str(i) + ' ' + chr(i))
        
printASCII()