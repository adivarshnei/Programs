# Program to check armstrong number

numStr = input("Enter the number: ")

numList = list(numStr)
numList = [int(n) for n in numList]

cubeList = [n ** 3 for n in numList]

if numStr == str(sum(cubeList)):
    print(f"{numStr} is an Armstrong number")
else:
    print(f"{numStr} is not an Armstrong number")