import pandas as pd
from matplotlib import pyplot as plt

# Data
data = pd.read_csv('data2.csv')
ages = data['Age']
dev_salaries = data['All_Devs']
py_salaries = data['Python']
js_salaries = data['JavaScript']

overall_median = 57287

plt.title('Median Salary (USD) by Age')
plt.xlabel('Ages')
plt.ylabel('Median Salary (USD)')

plt.plot(ages, dev_salaries, linestyle='--', label='All Devs')
plt.plot(ages, py_salaries, label='Python')

# plt.fill_between(ages, py_salaries, overall_median,
# where=(py_salaries > overall_median), interpolate=True, alpha=0.25)

# plt.fill_between(ages, py_salaries, overall_median, color='red',
# where=(py_salaries <= overall_median), interpolate=True, alpha=0.25)

plt.fill_between(ages, py_salaries, dev_salaries, label='Above Average',
                 where=(py_salaries > dev_salaries), interpolate=True, alpha=0.25)

plt.fill_between(ages, py_salaries, dev_salaries, color='red', label='Below Average',
                 where=(py_salaries <= dev_salaries), interpolate=True, alpha=0.25)

plt.legend()
plt.tight_layout()

plt.savefig("stack.png", bbox_inches='tight')
plt.show()
