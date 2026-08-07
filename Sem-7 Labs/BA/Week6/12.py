import pandas as pd
feature = pd.Series([15, 22, 8, 40, 30])
z = (feature - feature.mean()) / feature.std(ddof=0)
print('Standardized values:', z.round(3).tolist())
print('Mean :', round(z.mean(), 6))
print('Std :', round(z.std(ddof=0), 6))