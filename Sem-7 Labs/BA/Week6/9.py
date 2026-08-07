import pandas as pd
import numpy as np
data = pd.DataFrame({
    'Age':    [25, np.nan, 30, 22, np.nan, 28, 35, 40, np.nan, 27],
    'Salary': [50000, 52000, np.nan, 48000, 51000, np.nan, 60000, 62000, 58000, np.nan],
    'City':   ['A','B','A', np.nan, 'C','B','A','C','B', np.nan]
})
# (a) Deletion
data_dropna_rows = data.dropna() # drop rows with any NaN
data_dropna_cols = data.dropna(axis=1) # drop columns with any NaN
# (b) Mean / median / mode imputation
data_mean = data.copy()
data_mean['Age'] = data_mean['Age'].fillna(data_mean['Age'].mean())
data_mean['Salary'] = data_mean['Salary'].fillna(data_mean['Salary'].median())
data_mean['City'] = data_mean['City'].fillna(data_mean['City'].mode()[0])
# (c) Forward / backward fill
data_ffill = data.fillna(method='ffill')
data_bfill = data.fillna(method='bfill')
print('Original mean Age :', round(data['Age'].mean(), 2))
print('Mean-imputed Age :', round(data_mean['Age'].mean(), 2))
print('Original std Age :', round(data['Age'].std(), 2))
print('Mean-imputed std Age:', round(data_mean['Age'].std(), 2))