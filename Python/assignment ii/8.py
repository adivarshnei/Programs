#Program to find digit frequency

def digitFreq(num):
    freq = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    
    while num > 0:
        freq[num % 10] += 1
        num //= 10
        
    return freq
        
num = int(input("Enter the number: "))
freqTable = digitFreq(num)

for i in range(0, 10):
    print("Digit " + str(i) + " present " + str(freqTable[i]) + " times")