# Program to find all factors of a number

def factList(num):
    factors = []
    
    for i in range(1, num):
        if num % i == 0:
            factors.append(i)
    
    return factors

def printList(entList):
    for i in range(len(entList)):
        print(f"{entList[i]}", end='\t')

num = int(input("Enter the number: "))

print("Factor list: ")
printList(factList(num))