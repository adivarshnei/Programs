import csv
import numpy as np
import pandas as pd
from collections import Counter
from matplotlib import pyplot as plt

# Importing CSV(Method 1 - Using csv module)
# with open('data.csv') as csv_file:
#     csv_reader = csv.DictReader(csv_file)
#     language_counter = Counter()
#
#     for row in csv_reader:
#         language_counter.update(row['LanguagesWorkedWith'].split(';'))

# Importing CSV(Method 2 - Using pandas)
data = pd.read_csv('data.csv')
ids = data['Responder_id']
lang_responses = data['LanguagesWorkedWith']

language_counter = Counter()

for response in lang_responses:
    language_counter.update(response.split(';'))

languages = []
popularity = []

for item in language_counter.most_common(25):
    languages.append(item[0])
    popularity.append(item[1])

languages.reverse()
popularity.reverse()

plt.style.use('ggplot')
plt.title("Most Popular Languages")

# Horizontal Bar Chart
plt.barh(languages, popularity, label='Language Popularity')

plt.xlabel("Users")
# plt.ylabel("Programming Language")

plt.legend()
plt.tight_layout()

plt.savefig('bar/csv.png', bbox_inches='tight')
plt.show()
