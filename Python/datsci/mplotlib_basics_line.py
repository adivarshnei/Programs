import numpy as np
from matplotlib import pyplot as plt

# matplotlib styles
plt.style.use('ggplot')

# xkcd style
# plt.xkcd()

# Data
ages_x = [
    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
    37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55
]

dev_y = [
    17784, 16500, 18012, 20628, 25206, 30252, 34368, 38496, 42000, 46752,
    49320, 53200, 56000, 62316, 64928, 67317, 68748, 73752, 77232, 78000,
    78508, 79536, 82488, 88935, 90000, 90056, 95000, 90000, 91633, 91660,
    98150, 98964, 100000, 98988, 100000, 108923, 105000, 103117
]

py_dev_y = [
    20046, 17100, 20000, 24744, 30500, 37732, 41247, 45372, 48876, 53850,
    57287, 63016, 65998, 70003, 70000, 71496, 75370, 83640, 84666, 84392,
    78254, 85000, 87038, 91991, 100000, 94796, 97962, 93302, 99240, 102736,
    112285, 100771, 104708, 108423, 101407, 112542, 122870, 120000
]

js_dev_y = [
    16446, 16791, 18942, 21780, 25704, 29000, 34372, 37810, 43515, 46823,
    49293, 53437, 56373, 62375, 66674, 68745, 68746, 74583, 79000, 78508,
    79996, 80403, 83820, 88833, 91660, 87892, 96243, 90000, 99313, 91660,
    102264, 100000, 100000, 91660, 99240, 108000, 105000, 104000
]

x_index = np.arange(len(ages_x))

bar_width = 0.25

# Basic Line Plot
# plt.plot(x_index, py_dev_y, label="Python")
# plt.plot(x_index, js_dev_y, label="JavaScript")
# plt.plot(x_index, dev_y, label="All Devs")

# Line Plot with modifications
# plt.plot(x_index, py_dev_y, color='#5A7D9A', linestyle='--', marker='', linewidth=3, label='Python Devs')
# plt.plot(x_index, js_dev_y, color='#ADAD3B', linestyle='--', marker='', linewidth=3, label="Javascript")
# plt.plot(x_index, dev_y, color='#444444', linestyle='-', marker='', linewidth=2, label='All Devs')

# Bar plot
# plt.bar(x_index, py_dev_y, label="Python")
# plt.bar(x_index, js_dev_y, label="JavaScript")
# plt.bar(x_index, dev_y, color="#444444", label="All Devs")

# Side to Side Bar Plots
plt.bar(x_index - bar_width, py_dev_y, width=bar_width, label="Python")
plt.bar(x_index, js_dev_y, width=bar_width, label="JavaScript")
plt.bar(x_index + bar_width,
        dev_y,
        color="#444444",
        width=bar_width,
        label="All Devs")

# Axis Labels
plt.xlabel("Ages")  # x-axis label
plt.xticks(ticks=x_index, label=ages_x)  # x-axis markers
plt.ylabel("Median Salary(USD)")  # y-axis label

# Plot Title
plt.title('Median Salary (USD) by Age')

# Legend
# plt.legend(['All Devs', 'Python Devs'])

# Alternate (Better) Legend (Uses Labels)
plt.legend()

# Inserting a grid
# plt.grid(True)

# Adjust Padding Issues
plt.tight_layout()

# Exporting Plot
plt.savefig('plot.png', bbox_inches='tight')
# plt.savefig('plot.pdf', bbox_inches='tight')

# Shows Plot
plt.show()
