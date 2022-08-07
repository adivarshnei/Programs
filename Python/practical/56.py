# Program to swap two values using functions

def valSwap(val1, val2):
    val1, val2 = val2, val1
    
    return val1, val2

(val1, val2) = map(int, input("Enter the values: ").split(' '))

val1, val2 = valSwap(val1, val2)

print(f"The swapped values are: {val1}, {val2}")