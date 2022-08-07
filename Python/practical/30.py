# Program to convert binary to decimal

def binToDec(binNum):
    decNum = 0
    i = 1
    
    while binNum > 0:
        decNum = decNum + ((binNum % 10) * i)
        binNum = round(binNum / 10)
        i = i * 2
    
    return decNum
# binNum = int(input("Enter the binary number: "))
binNum = 10

print(f"Binary {binNum} = Decimal {binToDec(binNum)}")