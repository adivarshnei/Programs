# Program to check whether a character is an alphabet, digit

char = str(input("Enter the character: "))

charList = list(char)

print(charList)

for i in charList:
    if i.isalpha():
        print(f"'{i}' is a alphabet")
    elif i.isdigit():
        print(f"'{i}' is a digit")
    else:
        print(f"'{i}' is a special character")