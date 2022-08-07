# Program to find LCM

def HCFCalc(A, B):
    while B >= 1 :
        res = A % B
        A = B
        B = res
    
    return A

def LCMCalc(A, B):
    return int((A/HCFCalc(A, B)) * B)

print(f"Enter the numbers: ", end = '')
(A, B) = map(int, input().split())

print(f"LCM({A}, {B}) = {LCMCalc(A, B)}")