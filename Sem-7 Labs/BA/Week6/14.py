import pandas as pd, numpy as np
data_col = pd.Series([21, 23, 22, 24, 20, 90, 25, 19, 23, 22, -15])
Q1 = data_col.quantile(0.25)
Q3 = data_col.quantile(0.75)
IQR = Q3 - Q1
lower_bound = Q1 - 1.5 * IQR
upper_bound = Q3 + 1.5 * IQR
outliers = data_col[(data_col < lower_bound) | (data_col > upper_bound)]
print('Q1, Q3, IQR :', Q1, Q3, IQR)
print('Bounds :', lower_bound, upper_bound)
print('Outliers found:', outliers.tolist())
# Treat by capping (winsorizing)
treated = data_col.clip(lower=lower_bound, upper=upper_bound)
print('Treated data :', treated.tolist())