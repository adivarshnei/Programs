# Imported Libraries
import io
import os
from typing import Tuple

import numpy as np
from matplotlib import pyplot as plt
import seaborn as sns


# Gets the steps from the binary and linear text files, returns np arrays with
# the steps taken for linear search, steps taken for binary search, and an
# array with the numbers 1 to 2000
def get_steps() -> Tuple[np.ndarray, np.ndarray, np.ndarray]:
    exec_path: str = "gen_nums.c"
    linear_path: str = "linear.txt"
    binary_path: str = "binary.txt"

    # Calls the gcc compiler to compile the C program
    os.system(command=f"gcc {exec_path}")

    # Executes the C program to populate the text files with number of steps
    # taken by binary and linear searching
    os.system(command=f'a "{linear_path}" "{binary_path}"')

    linear_file: io.TextIOWrapper

    # Opens the linear search file and extracts the numbers in it to a np array
    with open(file=linear_path, mode="r") as linear_file:
        linear_str: str = linear_file.readline()

        linear_steps: np.ndarray = np.fromstring(
            string=linear_str, dtype=int, sep=" "
        )

    binary_file: io.TextIOWrapper

    # Opens the binary search file and extracts the numbers in it to a np array
    with open(binary_path, "r") as binary_file:
        binary_str: str = binary_file.readline()

        binary_steps: np.ndarray = np.fromstring(
            string=binary_str, dtype=int, sep=" "
        )

    # Creates a np array with integers starting with 1 to 2000
    iterations: np.ndarray = np.arange(
        start=1, stop=len(linear_steps) + 1, step=1, dtype=int
    )

    return (linear_steps, binary_steps, iterations)


# Plots the linear and binary search steps against the number of searches
# performed
def plot(
    iterations: np.ndarray, linear_steps: np.ndarray, binary_steps: np.ndarray
) -> None:
    # Sets the Seaborn aesthetics
    sns.set_style(style="ticks")

    # Plot the linear and binary search steps against the number of searches
    plt.plot(iterations, linear_steps, label="Linear Search")
    plt.plot(iterations, binary_steps, label="Binary Search")

    # Plot labels
    plt.xlabel(xlabel="Number of Searches")
    plt.ylabel(ylabel="Steps Taken to Search")

    # Plot title
    plt.title(
        label=(
            "Comparison of Linear and Binary Search on a randomly generated"
            + " array (20 elements)"
        )
    )

    # Activates plot legend
    plt.legend()

    plt.show()


# Main method
def main() -> None:
    # Get the linear search steps, binary search steps and number of searches
    linear_steps: np.ndarray
    binary_steps: np.ndarray
    iterations: np.ndarray
    linear_steps, binary_steps, iterations = get_steps()

    # Plot the appropriate values against each other
    plot(
        iterations=iterations,
        linear_steps=linear_steps,
        binary_steps=binary_steps,
    )


if __name__ == "__main__":
    main()
