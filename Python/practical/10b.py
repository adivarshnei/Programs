# Program to check whether an is a vowel or consonant

def isVowel(char):
    if char.lower() == 'a' or char == 'e' or char == 'i' or char == 'o' or char == 'u':
        return True
    else:
        return False

char = str(input("Enter the character: "))

charList = list(char)

print(charList)

for i in charList:
    if i.isalpha():
        if isVowel(i):
            print(f"'{i}' is a vowel")
        elif not isVowel(i):
            print(f"'{i}' is a consonant")
    elif i.isdigit():
        print(f"'{i}' is a digit")
    else:
        print(f"'{i}' is a special character")