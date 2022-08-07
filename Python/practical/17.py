# Program to generate library bill

days = int(input("Enter the number of days: "))

mem = True

if days <= 5 :
    totAmt = days * 0.5
elif days in range (5, 11):
    totAmt = (days - 5) * 1 + 5 * 0.5
else:
    totAmt = (days - 10) * 5 + (10 - 5) * 1 + 5 * 0.5

if days >= 30:
    mem = False

print(f"Fine for {days} days = {totAmt}")

if not mem:
    print("Membership is cancelled")