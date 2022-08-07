x = 0
y = 0
z = 0


def xfunc(x, y, z):
    return (1 / 27) * (85 - 6 * y + z)


def yfunc(x, y, z):
    return (1 / 15) * (72 - x - 2 * z)


def zfunc(x, y, z):
    return (1 / 54) * (110 - x - y)


count = 0

while True:
    print(f"{count}: {'%.6f'%x}, {'%.6f'%y}, {'%.6f'%z}")

    x1 = round(xfunc(x, y, z), 6)
    y1 = round(yfunc(x, y, z), 6)
    z1 = round(zfunc(x, y, z), 6)

    if (
        round(x, 4) == round(x1, 4)
        and round(y, 4) == round(y1, 4)
        and round(z, 4) == round(z1, 4)
    ):
        break

    x = x1
    y = y1
    z = z1

    count += 1

print(f"\n{'%.4f'%x}, {'%.4f'%y}, {'%.4f'%z}")
