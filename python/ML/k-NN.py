#LAB PROGRAM 05: Develop a program to implement k-Nearest Neighbour algorithm to classify the randomly generated 100 values of x in the range of [0,1]. Perform the following based on dataset generated. 
#a. Label the first 50 points {x1,……,x50} as follows: if (xi ≤ 0.5), then xi ∊ Class1, else xi ∊ Class2
#b. Classify the remaining points, x51,……,x100 using KNN. Perform this for k=1,2,3,4,5,20,30
# ---------------------------------------------
# Import required libraries
# ---------------------------------------------
import numpy as np
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
import warnings
warnings.filterwarnings('ignore')

# ---------------------------------------------
# Generate random data and labels
# ---------------------------------------------
values = np.random.rand(100)
labels = []

# Assign labels to first 50 values
for i in values[:50]:
    if i <= 0.5:
        labels.append("Class 1")
    else:
        labels.append("Class 2")

# Assign None to remaining 50 values (unlabeled)
labels += [None] * 50

# ---------------------------------------------
# Create DataFrame
# ---------------------------------------------
data = {
    "Point": [f"x < {i+1}" for i in range(100)],
    "Value": values,
    "Label": labels
}
df = pd.DataFrame(data)

# ---------------------------------------------
# Split data into labeled and unlabeled sets
# ---------------------------------------------
labeled_df = df[df["Label"].notna()]
x_train = labeled_df[["Value"]]
y_train = labeled_df["Label"]

unlabeled_df = df[df["Label"].isna()]
x_test = unlabeled_df[["Value"]]

# ---------------------------------------------
# True labels for evaluation
# ---------------------------------------------
true_labels = ["Class 1" if x <= 0.5 else "Class 2" for x in values[50:]]

# ---------------------------------------------
# Try different k values and evaluate accuracy
# ---------------------------------------------
k_values = [1, 2, 3, 4, 5, 20, 30]
results = {}
accuracies = {}

for k in k_values:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(x_train, y_train)
    predictions = knn.predict(x_test)
    results[k] = predictions
    accuracy = accuracy_score(true_labels, predictions) * 100
    accuracies[k] = accuracy
    print(f"Accuracy for k = {k} : {accuracy:.2f}%")
