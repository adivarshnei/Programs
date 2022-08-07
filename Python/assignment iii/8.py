# Program to print decimal of hex number

def HexToDec(hexNum):
    decNum = 0
    powIndex = 0
    
    for i in range(0, len(hexNum)):
        if hexNum[i] == '0':
            decNum += 0 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i] == '1':
            decNum += 1 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i] == '2':
            decNum += 2 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i] == '3':
            decNum += 3 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i] == '4':
            decNum += 4 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i] == '5':
            decNum += 5 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i] == '6':
            decNum += 6 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i] == '7':
            decNum += 7 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i] == '8':
            decNum += 8 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i] == '9':
            decNum += 9 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i].lower() == 'a':
            decNum += 10 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i].lower() == 'b':
            decNum += 11 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i].lower() == 'c':
            decNum += 12 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i].lower() == 'd':
            decNum += 13 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i].lower() == 'e':
            decNum += 14 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
        elif hexNum[i].lower() == 'f':
            decNum += 15 * (pow(16, len(hexNum) - powIndex - 1))
            powIndex += 1
    
    return decNum

hexNum = input("Enter the hexadecimal number: ")

print(f"{hexNum} in decimal is {HexToDec(hexNum)}")