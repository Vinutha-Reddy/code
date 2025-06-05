"""LAB PROGRAM 02: Develop a program to Compute the correlation matrix to understand the relationships between pairs of 
features. Visualize the correlation matrix using a heatmap to know which variables have strong 
positive/negative correlations. Create a pair plot to visualize pairwise relationships between features. Use 
California Housing dataset.  """

# ---------------------------------------------
# Import required libraries
# ---------------------------------------------
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import io

# ---------------------------------------------
# Load dataset from uploaded file
# ---------------------------------------------
df = pd.read_csv(io.BytesIO(uploaded['housing.csv']))

# ---------------------------------------------
# Keep only numeric columns for correlation analysis
# ---------------------------------------------
df = df.select_dtypes(include=['number'])

# ---------------------------------------------
# Compute and visualize the correlation matrix using a heatmap
# ---------------------------------------------
correlation_matrix = df.corr()

plt.figure(figsize=(10, 5))
sns.heatmap(correlation_matrix, cmap='coolwarm', annot=True)
plt.title("California dataset using heatmap")
plt.show()

# ---------------------------------------------
# Visualize pairwise relationships using pairplot
# ---------------------------------------------
sns.pairplot(df, height=2)
plt.suptitle("California dataset using pair plot")
plt.show()
