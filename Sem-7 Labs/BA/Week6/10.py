#error
import numpy as np, pandas as pd
from sklearn.impute import KNNImputer
from sklearn.experimental import enable_iterative_imputer # noqa
from sklearn.impute import IterativeImputer

data = pd.DataFrame({
    'Age':    [25, np.nan, 30, 22, np.nan, 28, 35, 40, np.nan, 27],
    'Salary': [50000, 52000, np.nan, 48000, 51000, np.nan, 60000, 62000, 58000, np.nan],
    'City':   ['A','B','A', np.nan, 'C','B','A','C','B', np.nan]
})

numeric = data[['Age', 'Salary']]
knn_imputer = KNNImputer(n_neighbors=3)
knn_result = pd.DataFrame(knn_imputer.fit_transform(numeric), columns=numeric.columns)
reg_imputer = IterativeImputer(random_state=0) # regression-based (MICE-style)
reg_result = pd.DataFrame(reg_imputer.fit_transform(numeric), columns=numeric.columns)
mean_result = numeric.fillna(numeric.mean())
comparison = pd.DataFrame({
 'Mean-imputed Age': mean_result['Age'],
 'KNN-imputed Age': knn_result['Age'],
 'Regression-imputed Age': reg_result['Age'],
})
print(comparison.round(2))