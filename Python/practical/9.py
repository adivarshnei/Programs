# Program to convert F to C and C to F

def tempConvert(inpTemp, convType):
    if convType == 1:
        resTemp = (inpTemp - 32) * (5 / 9)
    elif convType == 2:
        resTemp = (9 / 5) * inpTemp + 32
    
    return resTemp

convType = int(input("Enter the type of conversion (1 = F to C, 2 = C to F): "))
inpTemp = int(input("Enter the initial temperature: "))

if convType == 1:
    print(f"{float(inpTemp)} F = {tempConvert(inpTemp, convType)} C")
elif convType == 2:
    print(f"{float(inpTemp)} C = {tempConvert(inpTemp, convType)} F")