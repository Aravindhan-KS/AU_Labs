import pandas as pd, numpy as np, matplotlib.pyplot as plt
data = pd.DataFrame({
 'Age': [25, np.nan, 30, 22, np.nan, 28, 35, 40, np.nan, 27],
 'Salary': [50000, 52000, np.nan, 48000, 51000, np.nan, 60000, 62000, 58000, np.nan],
 'City': ['A','B','A', np.nan, 'C','B','A','C','B', np.nan]
})
missing_count = data.isnull().sum()
missing_pct = (data.isnull().mean() * 100).round(2)
summary = pd.DataFrame({'Missing Count': missing_count, 'Missing %': missing_pct})
print(summary)
missing_pct.plot(kind='bar', color='steelblue', title='Missing Value % per Column')
plt.ylabel('% missing'); plt.tight_layout(); plt.savefig('missing_values.png')