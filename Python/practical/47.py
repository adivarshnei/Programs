# Program to convert decimal to binary

import math

def decimalToBinary(decimal):
    binary = []
    
    while decimal > 0:
        binary.append(decimal % 2)
        decimal = math.floor(decimal / 2)
        
    binary.reverse()
    
    return binary

# decimal = int(input("Enter a decimal number: "))
decimal = 5

binary = decimalToBinary(decimal)

print(f"Decimal {decimal} = Binary {''.join(map(str, binary))}")