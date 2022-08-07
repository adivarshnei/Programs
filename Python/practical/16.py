# Program to print electricity bill

units = int(input("Enter the units of electricity: "))

if units < 200:
    totAmt = units * 1.2
elif units in range (200, 500):
    totAmt = (units - 199) * 1.8 + 199 * 1.2
else:
    totAmt = (units - 499) * 2 + (499 - 199) * 1.8 + 199 * 1.2
    
if totAmt >= 400:
    totAmt *= 1.15

if totAmt < 100:
    totAmt = 100

print(f"Amount for {units} units = {totAmt}")