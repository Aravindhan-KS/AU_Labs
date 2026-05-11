import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.preprocessing import StandardScaler
from sklearn import metrics
dataset = pd.read_csv("/home/machine/Desktop/ML/Iris.csv")
X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, 3].values
print(" Training Dataset\n")
print("\n", X)
print("\n", y)
X_train, X_test, y_train, y_test = train_test_split(X, y,test_size=0.20)
scaler = StandardScaler()
scaler.fit(X_train)
X_train = scaler.transform(X_train)
X_test = scaler.transform(X_test)
model= RandomForestRegressor(n_estimators=20, random_state=0)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
print('Mean Absolute Error:', metrics.mean_absolute_error(y_test,y_pred))
print('Mean Squared Error:', metrics.mean_squared_error(y_test,y_pred))
#print('Root Mean Squared Error:',
np.sqrt(metrics.mean_squared_error(y_test, y_pred))
print([9.1,85,8])
predicted = model.predict([[9.1,85,8]])
print(predicted)