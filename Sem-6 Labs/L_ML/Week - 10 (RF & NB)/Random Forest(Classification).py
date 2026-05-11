import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import StandardScaler
from sklearn import metrics
#Load the Iris data set.
dataset = pd.read_csv("/home/machine/Desktop/ML/Iris.csv")
# Split the Iris features into input and output columns
X = dataset.iloc[:, 1:5].values
y = dataset.iloc[:, 5].values
print(" Training Dataset\n")
print("\n", X)
print("\n", y)
# Split the data matrix into train and test dataset
X_train, X_test, y_train, y_test = train_test_split(X, y,
test_size=0.20)
#Train the model using RandomForestClassifier
model= RandomForestClassifier(n_estimators=20)
#Fit the model
model.fit(X_train,y_train)
#Predict the Output
y_pred = model.predict(X_test)
#Print the model accuracy
print("Accuracy:",metrics.accuracy_score(y_test, y_pred))