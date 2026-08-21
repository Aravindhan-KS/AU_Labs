import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA, KernelPCA, TruncatedSVD

np.random.seed(42)
n = 200
annual_income = np.random.normal(60000, 15000, n)
spending_score = 0.0006 * annual_income + np.random.normal(40, 10, n)         
purchase_frequency = 0.15 * spending_score + np.random.normal(5, 3, n)          
avg_purchase_value = 0.001 * annual_income + 0.4 * spending_score + np.random.normal(20, 8, n)
website_visits = 0.3 * purchase_frequency + np.random.normal(10, 4, n)
customer_age = np.random.normal(38, 12, n)

df = pd.DataFrame({
    "Annual_Income": annual_income,
    "Spending_Score": spending_score,
    "Purchase_Frequency": purchase_frequency,
    "Average_Purchase_Value": avg_purchase_value,
    "Website_Visits": website_visits,
    "Customer_Age": customer_age
})

df.loc[[3, 17, 45], "Website_Visits"] = np.nan

df.to_csv("customer_data.csv", index=False)

print("\nFirst five records:")
print(df.head())

print("\nMissing values per column:")
print(df.isnull().sum())

df = df.fillna(df.mean(numeric_only=True))

numerical_attributes = df.select_dtypes(include=[np.number]).columns.tolist()
print("\nNumerical attributes selected:", numerical_attributes)

X = df[numerical_attributes].values
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)
print("\nStandardized data (first 5 rows):")
print(pd.DataFrame(X_scaled, columns=numerical_attributes).head())


print("\n\nPRINCIPAL COMPONENT ANALYSIS (PCA)")

pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_scaled)

pca_df = pd.DataFrame(X_pca, columns=["PC1", "PC2"])
print("\nTransformed data (first 5 rows):")
print(pca_df.head())

pca_explained_variance = pca.explained_variance_ratio_
print("\nExplained variance ratio:", pca_explained_variance)
print("Total variance retained by 2 PCs: {:.2f}%".format(pca_explained_variance.sum() * 100))

plt.figure(figsize=(6, 5))
plt.scatter(X_pca[:, 0], X_pca[:, 1], c="royalblue", edgecolor="k", alpha=0.75)
plt.title("PCA - First Two Principal Components")
plt.xlabel("Principal Component 1")
plt.ylabel("Principal Component 2")
plt.grid(alpha=0.3)
plt.tight_layout()
plt.savefig("plot_pca.png", dpi=150)
plt.close()

print("\n\nKERNEL PCA (RBF KERNEL)")
kpca = KernelPCA(n_components=2, kernel="rbf", gamma=0.04)
X_kpca = kpca.fit_transform(X_scaled)

kpca_df = pd.DataFrame(X_kpca, columns=["KPC1", "KPC2"])
print("\nTransformed data (first 5 rows):")
print(kpca_df.head())

plt.figure(figsize=(6, 5))
plt.scatter(X_kpca[:, 0], X_kpca[:, 1], c="seagreen", edgecolor="k", alpha=0.75)
plt.title("Kernel PCA (RBF) - First Two Kernel Components")
plt.xlabel("Kernel Component 1")
plt.ylabel("Kernel Component 2")
plt.grid(alpha=0.3)
plt.tight_layout()
plt.savefig("plot_kpca.png", dpi=150)
plt.close()

print("\n\nSINGULAR VALUE DECOMPOSITION (SVD)")
svd = TruncatedSVD(n_components=2, random_state=42)
X_svd = svd.fit_transform(X_scaled)

svd_df = pd.DataFrame(X_svd, columns=["SVD1", "SVD2"])
print("\nReduced dataset (first 5 rows):")
print(svd_df.head())

svd_explained_variance = svd.explained_variance_ratio_
print("\nProportion of variance represented by the 2 singular vectors:", svd_explained_variance)
print("Total variance retained: {:.2f}%".format(svd_explained_variance.sum() * 100))

plt.figure(figsize=(6, 5))
plt.scatter(X_svd[:, 0], X_svd[:, 1], c="darkorange", edgecolor="k", alpha=0.75)
plt.title("SVD - First Two Components")
plt.xlabel("Singular Component 1")
plt.ylabel("Singular Component 2")
plt.grid(alpha=0.3)
plt.tight_layout()
plt.savefig("plot_svd.png", dpi=150)
plt.close()