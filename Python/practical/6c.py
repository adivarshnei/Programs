# Program to check whether number is even or odd

def typeChk(num):
    if num % 2 == 0:
        return True
    else:
        return False

num = int(input(f"Enter the number: "))

if typeChk(num) == True:
    print(f"{num} is an even number")
else:
    print(f"{num} is an odd number")