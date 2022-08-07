# Program to calculate the roots of a quadratic equation

import math

print("Quadratic equation of the type Ax^2 + Bx + C = 0")
(coeffA, coeffB, coeffC) = map(int, input("Enter the coefficients A, B and C: ").split())

disc = 0

disc = coeffB * coeffB - 4 * coeffA * coeffC

if disc >= 0:
    rootAlpha = (- coeffB + math.sqrt(disc)) / (2 * coeffA)
    rootBeta = (- coeffB - math.sqrt(disc)) / (2 * coeffA)
    
    print(f"For equation {coeffA}x^2 + {coeffB}x + {coeffC} = 0")
    print(f"Roots are {rootAlpha}, {rootBeta}")

else:
    realRoot = (- coeffB) / (2 * coeffA)
    imgRoot = (math.sqrt(abs(disc))) / (2 * coeffA)
    
    print("cmplx")
    
    print(f"For equation {coeffA}x^2 + {coeffB}x + {coeffC} = 0")
    print(f"Roots are {complex(realRoot, imgRoot)}, {complex(realRoot, imgRoot).conjugate()}")