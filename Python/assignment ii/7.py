# Program to swap first and last digit of number

def swapNum(num):
    res = ""
    
    for index, char in enumerate(str(num)):
        if index == 0:
            last = char
        elif index < len(str(num)) - 1:
            res += char
        else:
            res = char + res + last
    
    return int(res)

print("The number with swapped digits is: " + str(swapNum(int(input("Enter the number: ")))))