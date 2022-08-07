# Write a python program which accepts the radius of a circle from user and
# computes the area (use math module).

import math


def print_area(radius):
    area = math.pi * radius * radius

    print(f"Area of a circle with radius {radius} is {area}")


def main():
    radius = float(input("Enter the radius of the circle: "))

    print_area(radius)


if __name__ == "__main__":
    main()
