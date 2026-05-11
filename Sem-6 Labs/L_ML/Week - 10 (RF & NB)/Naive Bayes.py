from sklearn import datasets
from sklearn import metrics
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import train_test_split
# Load the Iris dataset
dataset = datasets.load_iris()
# Fit a Naive Bayes model to the data

model = GaussianNB()
X_train,X_test,y_train,y_test=train_test_split(dataset.data,dataset.target,test_size=0.30,random_state=2)
model.fit(X_train, y_train)
print(model)
# Make predictions
y_expected = y_test
y_predicted = model.predict(X_test)
# Evaluate the model and print the classification report, Confusion Matrix
print(metrics.classification_report(y_expected, y_predicted))
print(metrics.confusion_matrix(y_expected, y_predicted))