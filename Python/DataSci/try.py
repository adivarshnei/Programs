import pandas as pd
import seaborn as sns
from matplotlib import pyplot as plt

# plt.xkcd()

dataset = pd.read_csv("income.csv")
# dataset = sns.load_dataset("fmri")

data = dataset.head(500)[["age", "gender"]]
# print(data)

sns.boxplot(x="age", y="gender", data=data)
sns.swarmplot(x="age", y="gender", data=data,color=".25")
# sns.swarmplot(x="timepoint", y="signal", data=dataset)

# plt.title("Box Plots")
# plt.xlabel("Age")
# plt.ylabel("Job Type")

plt.show()
