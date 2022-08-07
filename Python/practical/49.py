# Program to find smallest and largest element in 10 integers

SIZE = 10

integers = []

for i in range(SIZE):
    element = int(input(f"Enter Integer {i + 1}: "))
    integers.append(element)

small = integers[0]
large = integers[0]

for i in range(SIZE):
    if small > integers[i]:
        small = integers[i]
    if large < integers[i]:
        large = integers[i]

print(f"Smallest element in array: {small}")
print(f"Largest element in array: {large}")