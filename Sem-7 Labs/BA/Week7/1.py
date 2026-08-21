import pandas as pd

import numpy as np
from sklearn.preprocessing import MinMaxScaler

data = {
    "CustomerID":       [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    "Age":              [25, np.nan, 35, 45, 29, np.nan, 41, 38, 22, 50],
    "Annual_Income":    [40000, 55000, np.nan, 72000, 48000, 61000, np.nan, 58000, 39000, 90000],
    "Purchase_Amount":  [200, 450, 300, np.nan, 150, 500, 620, np.nan, 180, 700],
}
df = pd.DataFrame(data)

print("Original Dataset")
print(df)


print("\n\nMissing Values per Column")
print(df.isnull().sum())

cols_to_fix = ["Age", "Annual_Income", "Purchase_Amount"]

for col in cols_to_fix:
    mean_val = df[col].mean()
    df[col] = df[col].fillna(mean_val)

print("\n\nDataset After Mean Imputation")
print(df)

print("\nMissing values after imputation:")
print(df[cols_to_fix].isnull().sum())

scaler = MinMaxScaler()
df[cols_to_fix] = scaler.fit_transform(df[cols_to_fix])


print("\n\nFinal Normalized Dataset (Min-Max, range 0-1)")
print(df.round(3))