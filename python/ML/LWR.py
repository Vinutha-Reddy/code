#LAB PROGRAM 06: Implement the non-parametric Locally Weighted Regression algorithm in order to fit data points. Select appropriate data set for your experiment and draw graphs.
# ---------------------------------------------
# Import required libraries
# ---------------------------------------------
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# ---------------------------------------------
# Define Gaussian kernel function
# ---------------------------------------------
def gaussian_kernel(x, x_query, tau):
    return np.exp(- (x - x_query)**2 / (2 * tau**2))

# ---------------------------------------------
# Define Locally Weighted Regression function
# ---------------------------------------------
def locally_weighted_regression(x, y, x_query, tau):
    x_b = np.c_[np.ones(len(x)), x]             # Add bias term to input features
    x_query_b = np.array([1, x_query])          # Query point with bias term
    w = np.diag(gaussian_kernel(x, x_query, tau))  # Weight matrix using Gaussian kernel
    theta = np.linalg.inv(x_b.T @ w @ x_b) @ x_b.T @ w @ y  # Normal equation with weights
    return x_query_b @ theta                     # Predicted value at x_query

# ---------------------------------------------
# Sample training data
# ---------------------------------------------
x = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
y = np.array([1, 2, 3, 4, 3.5, 5.5, 6, 6.5, 8, 8])

# Query points for prediction
x_query = np.linspace(1, 10, 100)
tau = 1.0  # Bandwidth parameter

# ---------------------------------------------
# Compute predictions using LWR
# ---------------------------------------------
y_lwr = np.array([locally_weighted_regression(x, y, x_q, tau) for x_q in x_query])

# ---------------------------------------------
# Plotting the results
# ---------------------------------------------
plt.figure(figsize=(10, 6))
plt.scatter(x, y, color='blue', label='Data Points')
plt.plot(x_query, y_lwr, color='red', label='Locally Weighted Regression')
plt.title("Locally Weighted Regression")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.grid(True)
plt.show()
