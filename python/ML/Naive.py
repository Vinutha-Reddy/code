# ---------------------------------------------
# Load Olivetti Faces dataset
# ---------------------------------------------
from sklearn.datasets import fetch_olivetti_faces
faces = fetch_olivetti_faces()
x = faces.data
y = faces.target

# ---------------------------------------------
# Split dataset into training and test sets
# ---------------------------------------------
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)

# ---------------------------------------------
# Train a Naive Bayes classifier
# ---------------------------------------------
from sklearn.naive_bayes import GaussianNB
gnb = GaussianNB()
gnb.fit(x_train, y_train)

# ---------------------------------------------
# Predict on test set
# ---------------------------------------------
y_pred = gnb.predict(x_test)

# ---------------------------------------------
# Evaluate model accuracy
# ---------------------------------------------
from sklearn.metrics import accuracy_score
accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy of Naive Bayes classifier on Olivetti Faces dataset: {accuracy*100:.2f}%")

# ---------------------------------------------
# Visualize predictions
# ---------------------------------------------
import matplotlib.pyplot as plt
n_samples = 10
plt.figure(figsize=(60, 10))

for i in range(n_samples):
    ax = plt.subplot(1, n_samples, i + 1)
    ax.imshow(x_test[i].reshape(64, 64), cmap='gray')
    ax.set_title(f"Pred: {y_pred[i]}\nTrue: {y_test[i]}")
    ax.axis('off')

plt.show()
