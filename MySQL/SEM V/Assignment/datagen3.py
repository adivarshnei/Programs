from __future__ import annotations
import random
import typing

Department: list[dict[str, typing.Any]] = [
    {"DEPT_NO": 14, "DEPT_NAME": "Systems"},
    {"DEPT_NO": 93, "DEPT_NAME": "Marketing"},
    {"DEPT_NO": 89, "DEPT_NAME": "HR"},
    {"DEPT_NO": 18, "DEPT_NAME": "Research"},
    {"DEPT_NO": 37, "DEPT_NAME": "Frontend"},
    {"DEPT_NO": 47, "DEPT_NAME": "Backend"},
]

Loc: list[str] = [
    "Dallas",
    "New York",
    "Boston",
    "San Francisco",
    "Seattle",
    "New Orleans",
]

Salary: range = range(5000, 25000)

Hiredate: range = range(1981, 1984)

for department in Department:
    print(f"\t(", end="")
    for _ in range(2):
        print(f"{random.randint(0,9)}", end="")
    print(f', "{department}"),')
