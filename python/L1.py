import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
df=pd.read_csv(r"C:\housing.csv")
nf=df.select_dtypes(include=[np.number]).columns
for i in nf:
  plt.figure(figsize=(10,5))
  sns.histplot(df[i],bins=30)
  plt.title("California Housing Dataset using histogram")
  plt.grid(True)
  plt.show()