# Program to calculate simple interest

princ = int(input("Enter the principle amount: "))
rate = int(input("Enter the rate of interest: "))
time = int(input("Enter the time period: "))

print(f"Simple Interest = {princ * rate * time / 100}")
print(f"Total Amount Payable = {princ * rate * time / 100 + princ}")