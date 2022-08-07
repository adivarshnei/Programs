# import seaborn as sns
import pandas as pd
# import numpy as np
# from matplotlib import pyplot as plt

data2019 = pd.read_csv("survey_results_public2019.csv")
# data2020 = pd.read_csv("survey_results_public2020.csv")

print(data2019.shape)

years = (
    data2019[["YearsCode", "YearsCodePro"]]
    .drop(
        data2019.index[
            (data2019["YearsCode"] == "Less than 1 year")
            | (data2019["YearsCode"] == "More than 50 years")
            | (data2019["YearsCodePro"] == "Less than 1 year")
            | (data2019["YearsCodePro"] == "More than 50 years")
        ]
    )
    .dropna()
)

# print(years["YearsCode"].astype(str).astype(int))
# # years.drop(years.index[years=="More than 50 years"])
# # years.dropna()

# sns.jointplot(
#     x=years["YearsCode"].astype(str).astype(int),
#     y=years["YearsCodePro"].astype(str).astype(int),
#     kind="kde",
#     shade=True
# )

# plt.show()

print(data2019.shape)