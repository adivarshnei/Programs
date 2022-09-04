# import random

# names = [
#     "Emílie Shōhei",
#     "Aleksy Toivo",
#     "Norbert Lailoken",
#     "Feidlimid Adrijan",
#     "Virginia Ríghnach",
#     "Aamir Jelka",
#     "Viola Francine",
#     "Gilles Yusuf",
#     "Doireann Gaëlle",
#     "Therapon Ayaz",
#     "Quirino Vivek",
#     "Afi Tessouat",
#     "Susann Chisom",
#     "Martialis Hacî",
#     "Chi Titilayo",
#     "Nicușor Sultan",
#     "Celyn Hilarion",
#     "Úrsula Dermid",
#     "Magni Mehmet",
#     "Robert Shariah",
#     "Nicușor Sultan",
#     "Celyn Hilarion",
#     "Úrsula Dermid",
#     "Magni Mehmet",
#     "Robert Shariah",
#     "Shelach Mateja",
#     "Gerd Kazimierz",
#     "Aaryan Ravi",
#     "Gaetana Onufriy",
#     "Signe Kgosi",
# ]

# for i in range(20):
#     print(f"(", end="")
#     for _ in range(5):
#         print(f"{random.randint(0,9)}", end="")

#     print(f", ", end="")

#     print(f'"{names[i]}"', end="")

#     print(f"")

import turtle

# window in right hand side of screen
turtle.setup(500,500,-1,0)

# you can comment this out to keep state inbetween runs
turtle.reset()

turtle.forward(100)
turtle.left(90)

turtle.exitonclick()
