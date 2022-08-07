# Program to find gross salary

basic = int(input("Enter the basic salary: "))

da = 0.4 * basic
hra = 0.2 * basic

print(f"Basic Salary: {float(basic)}")
print(f"DA: {da}")
print(f"HRA: {hra}")
print(f"Gross Salary: {basic + da + hra}")