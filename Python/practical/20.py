# Print sum of digits of integer

numStr = input("Enter number: ")
numList = list(numStr)

print(numList)

for i, j in enumerate(numList):
    numList[i] = int(numList[i])
    continue

print(numList)

digiSum = 0

print(f"Sum of digits of {numStr}: ")

for i, j in enumerate(numList):
    digiSum += numList[i]
    print(f"{numList[i]} ", end = '')
    
    try:
        numList[i+1]
        print(f" + ", end = '')
    except:
        pass

print(f" = {digiSum}")