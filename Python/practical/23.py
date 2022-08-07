# Program to check perfect number

def factList(num):
    fact = []
    
    for i in range (1, num):
        if num % i == 0:
            fact.append(i)
    
    return fact

num = int(input("Enter the number: "))

numSum = sum(factList(num))

if num == numSum:
    print(f"{num} is a perfect number")
else:
    print(f"{num} is not a perfect number")