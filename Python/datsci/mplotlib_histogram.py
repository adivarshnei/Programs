import pandas as pd
from matplotlib import pyplot as plt

plt.style.use('ggplot')

# Data
data = pd.read_csv('data3.csv')
ids = data['Responder_id']
ages = data['Age']

median_age = 29

# bins = [x for x in range(1, 101)]
# bins = [5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]
bins = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]

# Histogram
plt.hist(ages, bins=bins, log=True, edgecolor='black')

plt.title('Respondant Ages')
plt.xlabel('Ages')
plt.ylabel('Total Respondants')

# Draw a Vertical Line
plt.axvline(median_age, color="#2222DD", label='Age Median')

plt.legend()
plt.tight_layout()

plt.savefig("stack.png", bbox_inches='tight')
plt.show()
