# ---------------------------------------------
# Import necessary libraries
# ---------------------------------------------
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.decomposition import PCA

# ---------------------------------------------
# Load the Iris dataset
# ---------------------------------------------
iris = load_iris()
features = iris.data
target = iris.target

# ---------------------------------------------
# Apply PCA to reduce dimensions from 4 to 2
# ---------------------------------------------
pca = PCA(n_components=2)
features_pca = pca.fit_transform(features)

# ---------------------------------------------
# Create a DataFrame for the PCA result and add target
# ---------------------------------------------
pca_df = pd.DataFrame(data=features_pca, columns=["Principal Component 1", "Principal Component 2"])
pca_df["Target"] = target

# ---------------------------------------------
# Print target class names
# ---------------------------------------------
print(iris.target_names)

# ---------------------------------------------
# Plot the PCA-transformed data
# ---------------------------------------------
plt.figure(figsize=(10, 5))
colors = ['r', 'g', 'b']
for i, label in enumerate(iris.target_names):
    plt.scatter(
        pca_df[pca_df["Target"] == i]["Principal Component 1"],
        pca_df[pca_df["Target"] == i]["Principal Component 2"],
        color=colors[i],
        label=label
    )

plt.title("PCA on Iris Dataset (4 features to 2 features)", fontsize=14)
plt.xlabel("Principal Component 1", fontsize=12)
plt.ylabel("Principal Component 2", fontsize=12)
plt.legend(title="Species", loc="lower right")
plt.grid()
plt.show()
