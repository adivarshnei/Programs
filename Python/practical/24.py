# Program to find the sum of even numbers upto n terms

def evenSumFind(numOfTerms):
    sumVal = 0
    
    for i in range(1, numOfTerms + 1):
        sumVal += i * 2
        
        if i < numOfTerms:
            print(f"{i * 2} + ", end = "")
        else:
            print(f"{i * 2}", end = "")
    
    return sumVal

num = int(input("Enter the number of terms: "))

sumVal = evenSumFind(num)

print(f" = {sumVal}")