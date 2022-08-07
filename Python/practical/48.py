# Program to find product, sum, average, maximum and minimum n integers

size = int(input("Enter cardinality of set of numbers: "))

integers = []

for i in range(size):
    element = int(input(f"Enter Integer {i + 1}: "))
    integers.append(element)

numSum = 0
numProd = 1

minimum = integers[0]
maximum = integers[0]

for i in range(size):
    numSum = numSum + integers[i]
    numProd = numProd * integers[i]
    
    if minimum > integers[i]:
        minimum = integers[i]
    if maximum < integers[i]:
        maximum = integers[i]

numAvg = numSum / size

print(f"Sum of elements in array: {numSum}")
print(f"Product of elements in array: {numProd}")
print(f"Average of elements in array: {numAvg}")
print(f"Minimum element in array: {minimum}")
print(f"Maximum element in array: {maximum}")