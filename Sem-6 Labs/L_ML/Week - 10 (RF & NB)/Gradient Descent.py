import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

# Load Iris dataset
iris = datasets.load_iris()
X = iris.data[:, :2]   # Use first 2 features for simplicity
y = iris.target

# Convert to binary classification (Setosa vs Versicolor)
X = X[y != 2]
y = y[y != 2]

# Standardize features
scaler = StandardScaler()
X = scaler.fit_transform(X)

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# Initialize parameters
m, n = X_train.shape
weights = np.zeros(n)
bias = 0
learning_rate = 0.1
epochs = 1000

# Sigmoid function
def sigmoid(z):
    return 1 / (1 + np.exp(-z))

# Training using Gradient Descent
for epoch in range(epochs):
    
    # Linear model
    linear_model = np.dot(X_train, weights) + bias
    
    # Apply sigmoid
    y_pred = sigmoid(linear_model)
    
    # Compute gradients
    dw = (1/m) * np.dot(X_train.T, (y_pred - y_train))
    db = (1/m) * np.sum(y_pred - y_train)
    
    # Update parameters
    weights -= learning_rate * dw
    bias -= learning_rate * db

# Testing
linear_model_test = np.dot(X_test, weights) + bias
y_pred_test = sigmoid(linear_model_test)
y_pred_class = [1 if i > 0.5 else 0 for i in y_pred_test]

# Accuracy
accuracy = np.mean(y_pred_class == y_test)
print("Accuracy:", accuracy)