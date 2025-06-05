#LAB PROGRAM 04: For a given set of training data examples stored in a .CSV file,implement and demonstrate the Find-S algorithm to output a description of the set of all hypotheses consistent with the training examples.
# ---------------------------------------------
# Import pandas and load dataset
# ---------------------------------------------
import pandas as pd

# Load the CSV file
data = pd.read_csv(r"S-Algorithm.csv")

# Display the dataset
print(data)

# ---------------------------------------------
# Function to implement the Find-S algorithm
# ---------------------------------------------
def find_s_algorithm(data):
    attributes = data.iloc[:, :-1].values
    target = data.iloc[:, -1].values

    for i in range(len(target)):
        if str(target[i]).strip().lower() == "yes":
            hypothesis = attributes[i].copy()
            break

    for i in range(len(target)):
        if str(target[i]).strip().lower() == "yes":
            for j in range(len(hypothesis)):
                if hypothesis[j] != attributes[i][j]:
                    hypothesis[j] = "?"

    return hypothesis

# ---------------------------------------------
# Run the algorithm and display the result
# ---------------------------------------------
final_hypothesis = find_s_algorithm(data)
print("\nMost specific hypothesis:", final_hypothesis)
# ---------------------------------------------