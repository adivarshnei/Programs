# Program to find smallest of two numbers

(num1, num2) = map(int, input("Enter the numbers: ").split())

num = []

num.append(num1)
num.append(num2)

print(f"{min(num)} is the smallest of {num1} and {num2}")