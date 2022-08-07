# Program to check whether triangle is right, obtuse or acute

(ang1, ang2) = map(int, input("Enter two angles of the triangle: ").split())

if ang1 + ang2 - 180 >= 0:
    print(f"Triangle with two angles {ang1} and {ang2} is invalid")
else:
    ang3 = 180 - ang1 - ang2
    
    if ang1 == 90 or ang2 == 90 or ang3 == 90:
        print(f"Triangle is right triangle")
    elif ang1 > 90 or ang2 > 90 or ang3 > 90:
        print(f"Triangle is obtuse triangle")
    else:
        print(f"Triangle is acute triangle")