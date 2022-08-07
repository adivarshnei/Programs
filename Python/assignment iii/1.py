# Program to find power of a number

base = int(input("Enter the base number: "))
power = int(input("Enter the power: "))

res = 1

for i in range(power):
    res *= base
    
print(f"{base} ^ {power} = {res}")