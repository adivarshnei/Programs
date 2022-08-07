# Program to find first and last digit of number

num = int(input('Enter the number: '))

lastDig = num % 10

while num >= 10:
    num //= 10
    
firstDig = num

print('First Digit is: ' + str(firstDig))
print('Last Digit is: ' + str(lastDig))