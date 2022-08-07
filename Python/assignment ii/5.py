# Program to count number of digits

num = int(input('Enter the number: '))
digits = 0

while num > 0:
    digits += 1
    num //= 10

print("Number of digits: " + str(digits))