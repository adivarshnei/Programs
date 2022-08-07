# Program to find the largest of three numbers

(num1, num2, num3) = map(int, input("Enter the three numbers: ").split())

num = []

num.append(num1)
num.append(num2)
num.append(num3)

print(f"{max(num)} is the largest of {num1}, {num2} and {num3}")