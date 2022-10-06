import os

n = 1
i = 1
j = 1

while n <= 100:
    while i <= n:
        while j <= n:
            j = j * 2
            j = j + 1
        i = i + 1
    print([n, i, j])

    n = n + 1
