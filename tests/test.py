import pandas as pd

X = pd.DataFrame(
    {"col1": [1, 5, 9, 13], "col2": [2, 6, 10, 14], "col3": [3, 7, 11, 15]},
    index=["row0", "row1", "row2", "row3"],
)

X[X < 8] = 0

print(X)
