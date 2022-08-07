# Program to check whether program is equilateral, isosceles or scalene

(side1, side2, side3) = map(int, input(f"Enter the three sides of the triangle: ").split(' '))

validChk = 1

if side1 > side2 and side1 > side3:
    if side2 + side3 <= side1:
        validChk = 0
    else:
        validChk = 1
elif side2 > side1 and side2 > side3:
    if side1 + side3 <= side2:
        validChk = 0
    else:
        validChk = 1
elif side3 > side1 and side3 > side2:
    if side1 + side2 <= side3:
        validChk = 0
    else:
        validChk = 1

if validChk == 0:
    print(f"The triangle is invalid")
else:
    if side1 == side2 and side2 == side3:
        print(f"The triangle is equilateral")
    elif side1 == side2 or side2 == side3 or side1 == side3:
        print(f"The triangle is isosceles")
    else:
        print(f"The triangle is scalene")