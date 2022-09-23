from __future__ import annotations
import random
import typing
import datetime

import faker

department: list[dict[str, typing.Any]] = [
    {"DEPT_NO": 14, "DEPT_NAME": "Systems"},    #3151
    {"DEPT_NO": 93, "DEPT_NAME": "Marketing"},  #6267
    {"DEPT_NO": 89, "DEPT_NAME": "HR"},         #5050
    {"DEPT_NO": 18, "DEPT_NAME": "Research"},   #5669
    {"DEPT_NO": 37, "DEPT_NAME": "Frontend"},   #8908
    {"DEPT_NO": 47, "DEPT_NAME": "Backend"},    #7248
]

job: list[str] = [
    "Officer",
    "Manager",
    "Jr. Emp.",
    "Assistant"
]

dept_nos = [dept["DEPT_NO"] for dept in department]

loc: list[str] = [
    "Dallas",
    "New York",
    "Boston",
    "San Francisco",
    "Seattle",
    "New Orleans",
]

names: list[str] = [
    "Jose Santos",
    "Bruce Mitchell",
    "Wilma Wilkins",
    "Angelina Maxwell",
    "Bryant Stevens",
    "Beth Jordan",
    "Sophia Spencer",
    "Boyd Watkins",
    "Ramon Russell",
    "Traci Jones",
    "Donnie Robertson",
    "Lee Robbins",
    "Tom Morris",
    "Christina Harmon",
    "Marian Lucas",
    "Cecilia Hammond",
    "Vernon Bennett",
    "Stephen Lane",
    "Clarence Hamilton",
    "Bertha Pearson",
    "Chad Bowen",
    "Lyle Daniel",
    "Yvette Mcbride",
    "Roger Mccormick",
    "Wayne Myers",
    "Victor Boyd",
    "Amber Howard",
    "Isabel Taylor",
    "Pat Gardner",
    "Marta Pierce",
    "Eddie Greer",
    "Harvey Klein",
    "Oscar Reid",
    "Whitney Collier",
    "Caroline Evans",
    "Jill Powers",
    "Alexander Barnes",
    "Darin Alexander",
    "Carolyn Graves",
    "Kristopher Douglas",
    "Henry Barber",
    "Dean Allen",
    "Gloria Peterson",
    "Adrian Long",
    "Beverly Holt",
    "Terry Fleming",
    "Emanuel Barker",
    "Sonja Bush",
    "Ellis Brady",
    "Carlos Wise",
]

random.shuffle(names)

hiredate: range = range(1981, 1984)

fake = faker.Faker()

for i in range(50):
    print(f"\t(", end="")
    print(f"{random.randint(1000, 9999)}, ", end="")
    print(f'"{names[i]}", ', end="")
    print(f"{random.randint(5, 25)}000, ", end="")
    print(
        f'"{fake.date_between(start_date=datetime.date(year=1981, month=1, day=1), end_date=datetime.date(year=1985, month=1, day=1))}", ',
        end="",
    )
    print(f'"{random.choice(loc)}", ', end="")
    print(f"{random.randint(1000, 9999)}, ", end="")
    print(f"\"{random.choice(job)}\", ", end="")
    print(f"\"{random.choice(['A','B','C'])}\", ", end="")
    print(f"{random.choice(dept_nos)}", end="")
    print(f"),")
