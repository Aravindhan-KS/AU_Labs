Below is a **Machine Learning Lab Coding Cheat Sheet** for the common algorithms you will likely implement in your **Sem-6 ML Lab**.
This is designed so you can **quickly write the program in exams/labs without thinking too much**.

All examples use **Python + Scikit-Learn**.

---

# Machine Learning Lab Coding Cheat Sheet

## 1. Common Imports (Use for Almost All Programs)

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, confusion_matrix
```

---

# 1. Linear Regression

Used for **predicting continuous values**.

Example: house price prediction.

### Code Template

```python
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = LinearRegression()
model.fit(X_train,y_train)

prediction = model.predict(X_test)

print(prediction)
```

### Important Points

* Used for **regression problems**
* Predicts **continuous values**

---

# 2. Logistic Regression

Used for **binary classification**.

Example: spam detection.

### Code Template

```python
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pandas as pd

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = LogisticRegression()
model.fit(X_train,y_train)

pred = model.predict(X_test)

print("Accuracy:",accuracy_score(y_test,pred))
```

### Important Points

* Output between **0 and 1**
* Used for **classification**

---

# 3. Decision Tree

Creates a **tree structure for classification**.

### Code Template

```python
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pandas as pd

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = DecisionTreeClassifier()
model.fit(X_train,y_train)

pred = model.predict(X_test)

print("Accuracy:",accuracy_score(y_test,pred))
```

### Visualize Tree (Optional)

```python
from sklearn import tree

tree.plot_tree(model)
plt.show()
```

---

# 4. K-Nearest Neighbors (KNN)

Classification based on **nearest neighbors**.

### Code Template

```python
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pandas as pd

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = KNeighborsClassifier(n_neighbors=3)
model.fit(X_train,y_train)

pred = model.predict(X_test)

print("Accuracy:",accuracy_score(y_test,pred))
```

### Important Points

Distance used:

Euclidean Distance

[
d = \sqrt{(x_2-x_1)^2 + (y_2-y_1)^2}
]

---

# 5. Support Vector Machine (SVM)

Used for **classification with optimal hyperplane**.

### Code Template

```python
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pandas as pd

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = SVC(kernel='linear')

model.fit(X_train,y_train)

pred = model.predict(X_test)

print("Accuracy:",accuracy_score(y_test,pred))
```

### Kernel Types

* linear
* rbf
* poly

---

# 6. Naive Bayes

Used for **probabilistic classification**.

### Code Template

```python
from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pandas as pd

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = GaussianNB()

model.fit(X_train,y_train)

pred = model.predict(X_test)

print("Accuracy:",accuracy_score(y_test,pred))
```

---

# 7. K-Means Clustering

Used for **unsupervised learning**.

### Code Template

```python
from sklearn.cluster import KMeans
import pandas as pd

data = pd.read_csv("data.csv")

X = data.iloc[:,:]

model = KMeans(n_clusters=3)

model.fit(X)

labels = model.labels_

print(labels)
```

### Visualization

```python
plt.scatter(X.iloc[:,0],X.iloc[:,1],c=labels)
plt.show()
```

---

# 8. Confusion Matrix

Used to evaluate classification.

### Code

```python
from sklearn.metrics import confusion_matrix

cm = confusion_matrix(y_test,pred)

print(cm)
```

Matrix Format

```
          Predicted
          0     1
Actual 0 TN    FP
Actual 1 FN    TP
```

---

# 9. Accuracy Formula

[
Accuracy = \frac{TP + TN}{TP + TN + FP + FN}
]

---

# ML Program Structure (MEMORIZE THIS)

Almost **every ML lab program follows this structure**.

```python
1. Import libraries
2. Load dataset
3. Split dataset
4. Train model
5. Predict output
6. Evaluate performance
```

Example skeleton:

```python
import pandas as pd
from sklearn.model_selection import train_test_split

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = Algorithm()

model.fit(X_train,y_train)

pred = model.predict(X_test)

print(pred)
```

---

# Quick Viva Cheat Lines

**Linear Regression**

Predicts continuous output using linear equation.

**Logistic Regression**

Used for binary classification using sigmoid function.

**Decision Tree**

Tree structure using entropy or gini index.

**KNN**

Classifies based on nearest neighbors.

**SVM**

Finds optimal hyperplane separating classes.

**Naive Bayes**

Probabilistic classifier using Bayes theorem.

**K-Means**

Unsupervised clustering algorithm.

Good question. Your **ML lab syllabus usually includes more algorithms** beyond the ones I showed. Below is the **rest of the important algorithms** commonly asked in **Semester-6 ML labs** with **quick coding templates**.

I’ll keep them in the **same cheat-sheet style so you can memorize them quickly for exams.**

---

# Additional ML Algorithms Cheat Sheet

---

# 10. Artificial Neural Network (ANN / MLP)

Used for **complex pattern learning**.

Structure:

* Input Layer
* Hidden Layer
* Output Layer

### Code Template

```python
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = MLPClassifier(hidden_layer_sizes=(10,10), max_iter=500)

model.fit(X_train,y_train)

pred = model.predict(X_test)

print("Accuracy:",accuracy_score(y_test,pred))
```

### Important Points

* Uses **backpropagation**
* Multiple hidden layers possible

---

# 11. Perceptron

The **simplest neural network**.

Single neuron model.

### Code Template

```python
from sklearn.linear_model import Perceptron
from sklearn.model_selection import train_test_split
import pandas as pd

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = Perceptron()

model.fit(X_train,y_train)

pred = model.predict(X_test)

print(pred)
```

### Key Formula

Output:

[
y = w_1x_1 + w_2x_2 + b
]

Activation function decides output.

---

# 12. Random Forest

Ensemble learning method using **multiple decision trees**.

### Code Template

```python
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pandas as pd

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = RandomForestClassifier(n_estimators=100)

model.fit(X_train,y_train)

pred = model.predict(X_test)

print("Accuracy:",accuracy_score(y_test,pred))
```

### Important Points

* Uses **bagging**
* More accurate than single decision tree

---

# 13. Gradient Boosting

Sequential ensemble learning.

### Code Template

```python
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.model_selection import train_test_split
import pandas as pd

data = pd.read_csv("data.csv")

X = data.iloc[:,:-1]
y = data.iloc[:,-1]

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

model = GradientBoostingClassifier()

model.fit(X_train,y_train)

pred = model.predict(X_test)

print(pred)
```

---

# 14. Principal Component Analysis (PCA)

Used for **dimensionality reduction**.

### Code Template

```python
from sklearn.decomposition import PCA
import pandas as pd

data = pd.read_csv("data.csv")

X = data.iloc[:,:]

pca = PCA(n_components=2)

result = pca.fit_transform(X)

print(result)
```

### Purpose

* Reduce features
* Remove redundancy
* Speed up training

---

# 15. Hierarchical Clustering

Another **unsupervised clustering algorithm**.

### Code Template

```python
import scipy.cluster.hierarchy as sch
import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv("data.csv")

dendrogram = sch.dendrogram(sch.linkage(data,method='ward'))

plt.show()
```

### Output

* **Dendrogram**

Tree-like clustering structure.

---

# 16. Apriori Algorithm (Association Rule Mining)

Used in **market basket analysis**.

Example:

```
Milk → Bread
Bread → Butter
```

### Code Template

```python
from mlxtend.frequent_patterns import apriori
import pandas as pd

data = pd.read_csv("data.csv")

result = apriori(data, min_support=0.5)

print(result)
```

---

# Neural Network Concept

Structure of ANN:

```
Input Layer → Hidden Layer → Output Layer
```

Each neuron computes:

[
z = w_1x_1 + w_2x_2 + b
]

Activation functions:

* Sigmoid
* ReLU
* Tanh

---

# Important ML Algorithms Summary

| Algorithm           | Type         | Use                           |
| ------------------- | ------------ | ----------------------------- |
| Linear Regression   | Supervised   | Predict values                |
| Logistic Regression | Supervised   | Binary classification         |
| Decision Tree       | Supervised   | Rule-based classification     |
| KNN                 | Supervised   | Distance-based classification |
| SVM                 | Supervised   | Hyperplane classification     |
| Naive Bayes         | Supervised   | Probabilistic classification  |
| Neural Network      | Supervised   | Complex pattern learning      |
| Random Forest       | Supervised   | Ensemble classification       |
| K-Means             | Unsupervised | Clustering                    |
| PCA                 | Unsupervised | Dimensionality reduction      |
| Apriori             | Unsupervised | Association rules             |

---

# ML Lab Exam Tip

Most ML lab programs differ in **only one line**:

```python
model = AlgorithmName()
```

Examples:

```
LinearRegression()
DecisionTreeClassifier()
KNeighborsClassifier()
SVC()
GaussianNB()
MLPClassifier()
RandomForestClassifier()
```


