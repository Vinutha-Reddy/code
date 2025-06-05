"""LAB PROGRAM 08: Develop a program to demonstrate the working of the decision tree algorithm. Use Breast Cancer Data set 
for building the decision tree and apply this knowledge to classify a new sample."""
# ---------------------------------------------
# Import required libraries
# ---------------------------------------------
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score
from sklearn import tree

# ---------------------------------------------
# Load Breast Cancer dataset
# ---------------------------------------------
data = load_breast_cancer()
x = data.data
y = data.target

# ---------------------------------------------
# Split the dataset into training and testing sets
# ---------------------------------------------
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)

# ---------------------------------------------
# Train a Decision Tree Classifier
# ---------------------------------------------
clf = DecisionTreeClassifier(random_state=42)
clf.fit(x_train, y_train)

# ---------------------------------------------
# Predict on test set and evaluate accuracy
# ---------------------------------------------
y_pred = clf.predict(x_test)
accuracy = accuracy_score(y_test, y_pred)
print(f"Model Accuracy: {accuracy*100:.2f}%")

# ---------------------------------------------
# Predict a class for a new sample
# ---------------------------------------------
new_sample = np.array([x_test[0]])
prediction = clf.predict(new_sample)
prediction_class = "Benign" if prediction == 1 else "Malignant"
print(f"Predicted Class for the new sample: {prediction_class}")

# ---------------------------------------------
# Visualize the decision tree
# ---------------------------------------------
plt.figure(figsize=(12, 8))
tree.plot_tree(clf, filled=True, feature_names=data.feature_names, class_names=data.target_names)
plt.title("Decision Tree - Breast Cancer Dataset")
plt.show()
