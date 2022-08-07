# Program to check palindromality of number

initNumStr = input("Enter the number: ")
initNumList = list(initNumStr)

revNumList = reversed(initNumList)
revNumStr = ''.join(map(str, revNumList))

if initNumStr == revNumStr:
    print(f"Original Number: {initNumStr}")
    print(f"Reversed Number: {revNumStr}")
    print("Palindrome Number")
else:
    print(f"Original Number: {initNumStr}")
    print(f"Reversed Number: {revNumStr}")
    print("Non Palindrome Number")