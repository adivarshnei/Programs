import math

fname = input("Enter the file name: ")

fhand = open(fname)

lineList = []

for line in fhand:
    if line.startswith("X-DSPAM-Confidence: "):
        lineList.append(line [20:-1])
        
    continue

datSum = 0

for index, data in enumerate(lineList):
    datSum += float(lineList[index])

print(f"{datSum/index}")