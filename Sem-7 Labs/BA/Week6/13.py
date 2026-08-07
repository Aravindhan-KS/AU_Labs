import numpy as np, pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans
df = pd.DataFrame({
 'Age': [25, 45, 35, 23, 52, 46, 30, 41],
 'Income': [25000, 120000, 60000, 20000, 150000, 130000, 55000, 90000]
})
# --- Before scaling ---
km_raw = KMeans(n_clusters=2, random_state=0, n_init=10).fit(df)
print('Clusters (raw) :', km_raw.labels_)
# --- After scaling ---
scaled = StandardScaler().fit_transform(df)
km_scaled = KMeans(n_clusters=2, random_state=0, n_init=10).fit(scaled)
print('Clusters (scaled):', km_scaled.labels_)
