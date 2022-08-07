# Program to find the location of a coordinate point

(x, y) = map(int, input("Enter the coordinates: ").split())

if x == 0 and y == 0:
    print(f"The coordinate ({x}, {y}) is the origin")
elif x >= 0 and y == 0:
    print(f"The coordinate ({x}, {y}) is on the x axis right to the origin")
elif x <= 0 and y ==0:
    print(f"The coordinate ({x}, {y}) is on the x axis left to the origin")
elif x == 0  and y >= 0:
    print(f"The coordinate ({x}, {y}) is on the y axis above the origin")
elif x == 0 and y <= 0:
    print(f"The coordinate ({x}, {y}) is on the y axis below the origin")
elif x >= 0 and y >= 0:
    print(f"The coordinate ({x}, {y}) is in the first quadrant")
elif x <= 0 and y >= 0:
    print(f"The coordinate ({x}, {y}) is in the second quadrant")
elif x <= 0 and y <= 0:
    print(f"The coordinate ({x}, {y}) is in the third quadrant")
elif x >= 0 and y <= 0:
    print(f"The coordinate ({x}, {y}) is in the fourth quadrant")