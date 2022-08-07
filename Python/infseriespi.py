import math
from matplotlib import pyplot as plt
import numpy as np


def factorial(x):
    facProd = 1

    for i in range(1, x + 1):
        facProd *= i

    return facProd


def doubleFactorialSeries(terms):
    termSum = 0

    for i in range(0, terms + 1):
        termSum += pow(2, i) * pow(factorial(i), 2) / factorial(2 * i + 1)

    return termSum * 2


def baileyBorweinPlouffe(terms):
    termSum = 0
    partSum = 0

    for i in range(0, terms + 1):
        partSum += 4 / (8 * i + 1)
        partSum -= 2 / (8 * i + 4)
        partSum -= 1 / (8 * i + 5)
        partSum -= 1 / (8 * i + 6)
        partSum /= pow(16, i)

        termSum += partSum
        partSum = 0

    return termSum


def basel(terms):
    termSum = 0

    for i in range(1, terms + 1):
        termSum += 1 / pow(i, 2)

    return math.sqrt(termSum * 6)


def leibniz(terms):
    termSum = 0

    for i in range(0, terms + 1):
        termSum += pow(-1, i) / (2 * i + 1)

    return 4 * termSum


def wallis(terms):
    termProd = 1
    partProd = 1

    for i in range(1, terms + 1):
        partProd *= 4 * pow(i, 2)
        partProd /= 4 * pow(i, 2) - 1

        termProd *= partProd
        partProd = 1

    return termProd * 2


def viete(terms):
    termProd = 1
    partProd = math.sqrt(2)
    termProd *= partProd / 2

    for i in range(1, terms + 1):
        partProd += 2
        partProd = math.sqrt(partProd)
        termProd *= partProd / 2

    return 2 / termProd


plt.style.use("seaborn-notebook")

dfs = np.array([])
bbp = np.array([])
bas = np.array([])
lei = np.array([])
wal = np.array([])
vie = np.array([])
xAxis = np.array([])
piLine = np.array([])

for i in range(1, 110):
    xAxis = np.append(xAxis, np.array([i]))
    dfs = np.append(dfs, np.array([doubleFactorialSeries(i)]))
    bbp = np.append(bbp, np.array([baileyBorweinPlouffe(i)]))
    bas = np.append(bas, np.array([basel(i)]))
    lei = np.append(lei, np.array([leibniz(i)]))
    wal = np.append(wal, np.array([wallis(i)]))
    vie = np.append(vie, np.array([viete(i)]))
    piLine = np.append(piLine, np.array([math.pi]))

plt.plot(xAxis, lei, label="Leibniz's Formula")
plt.plot(xAxis, dfs, label="Double Factorial Formula")
plt.plot(xAxis, bbp, label="Bailey-Borwein-Plouffe Formula")
plt.plot(xAxis, bas, label="Basel Problem")
plt.plot(xAxis, wal, label="Wallis Product")
plt.plot(xAxis, vie, label="Viete's Formula")
plt.plot(xAxis, piLine, linestyle="dotted")
plt.legend()

plt.xlabel("Number of Terms")
plt.ylabel("Value")
plt.title("Different Series to Calculate pi")
plt.tight_layout()

plt.plot(math.pi, linestyle="dotted")

plt.show()

# import matplotlib.pyplot as plt
# import numpy as np

# x = np.linspace(0, 10*np.pi, 100)
# y = np.sin(x)

# plt.ion()
# fig = plt.figure()
# ax = fig.add_subplot(111)
# line1, = ax.plot(x, y, 'b-')

# for phase in np.linspace(0, 10*np.pi, 100):
#     line1.set_ydata(np.sin(0.5 * x + phase))
#     fig.canvas.draw()
