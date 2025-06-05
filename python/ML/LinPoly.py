"""LAB PROGRAM 07: Develop a program to demonstrate the working of Linear Regression and Polynomial Regression. Use 
Boston Housing Dataset for Linear Regression and Auto MPG Dataset (for vehicle fuel efficiency prediction) 
for Polynomial Regression."""
# ---------------------------------------------
# Imports
# ---------------------------------------------
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# ---------------------------------------------
# If using CSV
df = pd.read_csv(r"housing.csv")  

# ---------------------------------------------
# Feature and target selection
# ---------------------------------------------
x = df[["median_income"]]
y = df["median_house_value"]

# ---------------------------------------------
# Train-test split
# ---------------------------------------------
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=42)

# ---------------------------------------------
# Linear Regression
# ---------------------------------------------
from sklearn.linear_model import LinearRegression
linear_reg = LinearRegression()
linear_reg.fit(x_train, y_train)
y_pred = linear_reg.predict(x_test)

# ---------------------------------------------
# Polynomial Regression (degree = 3)
# ---------------------------------------------
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline

poly = make_pipeline(PolynomialFeatures(degree=3), LinearRegression())
poly.fit(x_train, y_train)
y_pred_poly = poly.predict(x_test)

# ---------------------------------------------
# Visualization - Linear Regression
# ---------------------------------------------
plt.scatter(x_test, y_test, color='blue', label="Actual")
plt.plot(x_test["median_income"], y_pred, color='red', label="Predicted")
plt.title("Linear Regression")
plt.xlabel("Median Income")
plt.ylabel("Median House Value")
plt.legend()
plt.show()

# ---------------------------------------------
# Visualization - Polynomial Regression
# ---------------------------------------------
plt.scatter(x_test, y_test, color='blue', label="Actual")
plt.scatter(x_test, y_pred_poly, color='red', label="Predicted")
plt.title("Polynomial Regression")
plt.xlabel("Median Income")
plt.ylabel("Median House Value")
plt.legend()
plt.show()
