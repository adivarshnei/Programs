import random

names: "list[str]" = [
    "Emílie Shōhei",
    "Aleksy Toivo",
    "Norbert Lailoken",
    "Feidlimid Adrijan",
    "Virginia Ríghnach",
    "Aamir Jelka",
    "Viola Francine",
    "Gilles Yusuf",
    "Doireann Gaëlle",
    "Therapon Ayaz",
    "Quirino Vivek",
    "Afi Tessouat",
    "Susann Chisom",
    "Martialis Hacî",
    "Chi Titilayo",
    "Nicușor Sultan",
    "Celyn Hilarion",
    "Úrsula Dermid",
    "Magni Mehmet",
    "Robert Shariah",
    "Nicușor Sultan",
    "Celyn Hilarion",
    "Úrsula Dermid",
    "Magni Mehmet",
    "Robert Shariah",
    "Shelach Mateja",
    "Gerd Kazimierz",
    "Aaryan Ravi",
    "Gaetana Onufriy",
    "Signe Kgosi",
]

cities: "list[str]" = [
    "Klaxstea",
    "Straford",
    "Bedtin",
    "Volas",
    "Zimland",
    "Fand",
    "Khora",
    "Boni",
    "Ontgas",
    "Anegan",
]

prospectus_no: "list[int]" = [
    30336,
    80652,
    96013,
    43852,
    55850,
    52238,
    96858,
    94311,
    56924,
    97257,
    15345,
    39524,
    40515,
    89292,
    88905,
    11443,
    65459,
    73579,
    41867,
    97528,
]

course_no: "list[str]" = [
    "5451",
    "6197",
    "2470",
    "4887",
    "5876",
    "5359",
    "5374",
    "3280",
    "8701",
    "0150",
    "5164",
    "7828",
    "3981",
    "4416",
    "1633",
    "5144",
    "4722",
    "5709",
    "8402",
    "0161",
    "3628",
    "1738",
    "6016",
    "6698",
    "7366",
    "8495",
    "9345",
    "8349",
    "3626",
    "3663",
    "2926",
    "7612",
    "8098",
    "3953",
    "3494",
    "8381",
    "9744",
    "6005",
    "5839",
    "2938",
]

# i: int
# for i in range(20):
#     print(f"    (", end="")

#     for _ in range(5):
#         print(f"{random.randint(0,9)}", end="")
#     print(f", ", end="")

#     print(f'"{names[i]}", ', end="")

#     print(f"\"{random.choice(cities)}\", ", end="")

#     i: int
#     for i in range(10):
#         if i == 0:
#             print(f"{random.randint(1,9)}", end="")
#         else:
#             print(f"{random.randint(0, 9)}", end="")
#     print(f", ", end="")

#     year: int = random.randint(1996, 2002)
#     month: int = random.randint(1, 12)

#     if month in [1, 3, 5, 7, 8, 10, 12]:
#         print(f'"{year}-{month}-{random.randint(1,31)}", ', end="")
#     elif month in [4, 6, 9, 11]:
#         print(f'"{year}-{month}-{random.randint(1,30)}", ', end="")
#     else:
#         if year % 4 == 0:
#             if year % 100 == 0:
#                 if year % 400 == 0:
#                     day: int = random.randint(1, 29)
#                 else:
#                     day: int = random.randint(1, 28)
#             else:
#                 day: int = random.randint(1, 29)
#         else:
#             day: int = random.randint(1, 28)
#         print(f'"{year}-{month}-{random.randint(1,28)}", ', end="")

#     print(f"{random.randint(10, 99)}00, {random.randint(10, 99)}00, ", end="")

#     print(f'"{random.choice(["I","F"])}"', end="")

#     print(f"),")

# random.shuffle(prospectus_no)

# i: int
# for i in range(20):
#     print("    (", end="")
#     print(f"{prospectus_no[i]}, ", end="")

#     print(f"{random.randint(10, 99)}0, ", end="")

#     year: int = random.randint(2022, 2023)
#     month: int = random.randint(1, 12)

#     if month in [1, 3, 5, 7, 8, 10, 12]:
#         print(f'"{year}-{month}-{random.randint(1,31)}", ', end="")
#     elif month in [4, 6, 9, 11]:
#         print(f'"{year}-{month}-{random.randint(1,30)}", ', end="")
#     else:
#         print(f'"{year}-{month}-{random.randint(1,28)}", ', end="")

#     print(f"\"{random.choice(['P','U'])}\"),", end="")
#     print(f"")

# CREATE TABLE Course_Taken_0129 (
#     PROSPECTUS_NO   INTEGER(10) NOT NULL    UNIQUE,
#     COURSE_NO       CHAR(4)     NOT NULL    UNIQUE,
#     START_DT        DATE,
#     FULL_PART       CHAR(1)     NOT NULL
#     CHECK (
#         FULL_PART = "F"
#         OR FULL_PART = "P"
#     ),
#     TIME_SLOT       CHAR(2),
#     PERFORMANCE     VARCHAR(20),

#     CONSTRAINT
#         FOREIGN KEY(PROSPECTUS_NO) REFERENCES Student_0129(PROSPECTUS_NO),
#     CONSTRAINT FOREIGN KEY(COURSE_NO) REFERENCES Course_0129(COURSE_NO)
# );

random.shuffle(prospectus_no)
random.shuffle(course_no)

i: int
for i in range(20):
    print(f"    (", end="")

    print(f"{prospectus_no[i]}, ", end="")
    print(f'"{course_no[i]}", ', end="")

    year: int = random.randint(2018, 2020)
    month: int = random.randint(1, 12)

    if month in [1, 3, 5, 7, 8, 10, 12]:
        print(f'"{year}-{month}-{random.randint(1,31)}", ', end="")
    elif month in [4, 6, 9, 11]:
        print(f'"{year}-{month}-{random.randint(1,30)}", ', end="")
    else:
        if year % 4 == 0:
            if year % 100 == 0:
                if year % 400 == 0:
                    day: int = random.randint(1, 29)
                else:
                    day: int = random.randint(1, 28)
            else:
                day: int = random.randint(1, 29)
        else:
            day: int = random.randint(1, 28)
        print(f'"{year}-{month}-{random.randint(1,28)}", ', end="")

    print(f"\"{random.choice(['F', 'P'])}\", ", end="")
    print(f"\"{random.choice(['1', '2', '3'])}\", ", end="")
    print(
        f'"'
        + f"{random.choice(['excellent', 'good', 'satisfactory', 'unsatisfactory'])}"
        + f'"',
        end="",
    )
    
    print(f"),")

for _ in range(20):
    print(random.choice(["2926","7612","8098","3953","3494","8381","9744","6005","5839","2938"]))
