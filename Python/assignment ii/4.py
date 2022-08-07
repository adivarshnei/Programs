# Print multable of any number

num = int(input("Enter Number: "))

for i in range(1, 11):
    print(str(num) + " * " + str(i) + " = " + str(num * i))