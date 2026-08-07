import pandas as pd, numpy as np
from sklearn.pipeline import Pipeline
from sklearn.compose import ColumnTransformer
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler, OneHotEncoder
df = pd.DataFrame({
 'Age': [25, np.nan, 30, 22, np.nan, 28],
 'Salary': [50000, 52000, np.nan, 48000, 51000, 60000],
 'City': ['A', 'B', 'A', np.nan, 'C', 'B']
})
numeric_features = ['Age', 'Salary']
categorical_features = ['City']
numeric_pipeline = Pipeline(steps=[
 ('imputer', SimpleImputer(strategy='median')),
 ('scaler', StandardScaler())
])
categorical_pipeline = Pipeline(steps=[
 ('imputer', SimpleImputer(strategy='most_frequent')),
 ('encoder', OneHotEncoder(handle_unknown='ignore'))
])
preprocessor = ColumnTransformer(transformers=[
 ('num', numeric_pipeline, numeric_features),
 ('cat', categorical_pipeline, categorical_features)
])
full_pipeline = Pipeline(steps=[('preprocessing', preprocessor)])
processed = full_pipeline.fit_transform(df)
print(processed)