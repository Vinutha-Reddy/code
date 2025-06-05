"""LAB PROGRAM 10: Develop a program to implement k-means clustering using Wisconsin Breast Cancer data set and visualize 
the clustering result."""
# ---------------------------------------------
# Upload the dataset (Colab-specific)
# ---------------------------------------------
from google.colab import files
uploaded = files.upload()

# ---------------------------------------------
# Read the uploaded file into a DataFrame
# ---------------------------------------------
import pandas as pd
import io
df = pd.read_csv(io.BytesIO(uploaded['Wisconsin Breast Cancer dataset.csv']))

# ---------------------------------------------
# Import required libraries
# ---------------------------------------------
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.cluster import KMeans
import warnings
warnings.filterwarnings('ignore')

# ---------------------------------------------
# Load dataset and drop unnecessary columns
# ---------------------------------------------
data = pd.read_csv("Wisconsin Breast Cancer dataset.csv")
df = data.drop(['id', 'Unnamed: 32'], axis=1)

# ---------------------------------------------
# Select features for clustering (excluding diagnosis column)
# ---------------------------------------------
x = df.iloc[:, 1:]

# ---------------------------------------------
# Apply K-Means Clustering (2 clusters)
# ---------------------------------------------
kmeans = KMeans(n_clusters=2, random_state=42)
kmeans.fit(x)
pred = kmeans.predict(x)

# ---------------------------------------------
# Plotting the clusters using 2 features
# ---------------------------------------------
print(x.iloc[:, 0])  # radius_mean
print(x.iloc[:, 1])  # texture_mean

plt.figure(figsize=(10, 6))
plt.scatter(x.iloc[:, 0], x.iloc[:, 1], c=pred, cmap='viridis', marker='o', label='Data Points')
plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], 
            s=100, c='red', marker='^', label='Centroids')

plt.xlabel('radius_mean')
plt.ylabel('texture_mean')
plt.title('K-Means Clustering on Breast Cancer Dataset')
plt.legend()
plt.grid(True)
plt.show()
