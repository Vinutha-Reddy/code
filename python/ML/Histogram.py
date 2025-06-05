"""LAB PROGRAM 01: Develop a program to create histograms for all numerical features and analyze the distribution of each 
feature. Generate box plots for all numerical features and identify any outliers. Use California Housing 
dataset.""" 

# ---------------------------------------------
# Import required libraries
# ---------------------------------------------
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# ---------------------------------------------
# Load the dataset from uploaded CSV
# ---------------------------------------------
df = pd.read_csv(r"housing.csv")

# ---------------------------------------------
# Identify numeric columns
# ---------------------------------------------
nf = df.select_dtypes(include=[np.number]).columns

# ---------------------------------------------
# Plot histograms for numeric columns
# ---------------------------------------------
for i in nf:
    plt.figure(figsize=(10, 5))
    sns.histplot(df[i], bins=30)
    plt.title("California Housing Dataset using histogram")
    plt.grid(True)
    plt.show()

# ---------------------------------------------
# Plot boxplots for numeric columns
# ---------------------------------------------
for i in nf:
    plt.figure(figsize=(10, 5))
    sns.boxplot(df[i])
    plt.title("California Housing Dataset using boxplot")
    plt.grid(True)
    plt.show()

# ---------------------------------------------
# Detect and count non-outlier data points using IQR method
# ---------------------------------------------
for i in nf:
    q1 = df[i].quantile(0.25)
    q3 = df[i].quantile(0.75)
    IQR = q3 - q1
    l_bound = q1 - 1.5 * IQR
    u_bound = q3 + 1.5 * IQR
    outliers = df[(df[i] >= l_bound) & (df[i] <= u_bound)]
    print(f"{i}", len(outliers))
