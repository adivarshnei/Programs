# Program to find HCF

def HCFCalc(A, B):
    while B >= 1 :
        res = A % B
        A = B
        B = res
    
    return A

print(f"Enter the numbers: ", end = '')
(A, B) = map(int, input().split())

print(f"HCF({A}, {B}) = {HCFCalc(A, B)}")