# Print summ of all odd numbers between 1 to n

n = int(input("Enter the Number Limit: "))
sum = 0

for i in range(1, n + 1):
    sum += i

print("Sum of the digits are: " + str(sum))