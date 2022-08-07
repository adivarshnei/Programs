import pandas as pd
from collections import Counter
from matplotlib import pyplot as plt

plt.style.use('ggplot')

# slices = [120, 80, 30, 20]
# labels = ['un', 'deux', 'trois', 'quatre']
# colors = ['blue', 'red', 'yellow', 'green']

# Data
data = pd.read_csv('data.csv')
ids = data['Responder_id']
lang_responses = data['LanguagesWorkedWith']

language_counter = Counter()

for response in lang_responses:
    language_counter.update(response.split(';'))

languages = []
popularity = []

for item in language_counter.most_common(7):
    languages.append(item[0])
    popularity.append(item[1])


# Emphasis on a single slice
explode = [0, 0, 0, 0.1, 0, 0, 0]

# Drawing a pie chart
# plt.pie(slices, labels=labels, colors=colors, wedgeprops={'edgecolor': 'black'})
plt.pie(popularity, labels=languages, explode=explode,
        shadow=True, startangle=90, autopct='%1.1f%%', wedgeprops={'edgecolor': 'black'})

plt.title("Pie Chart")
plt.tight_layout()

plt.savefig("pie.png", bbox_inches='tight')
plt.show()
