#!/usr/bin/python3
import math
import sys


def factorize(number):
    factors = []
    for i in range(2, int(math.isqrt(number)) + 1):
        if number % i == 0:
            factors.append(i)
            factors.append(number // i)
            break  # Stop after finding two factors
    return factors


# Check if the user has provided the file path as an argument
if len(sys.argv) < 2:
    print("Please provide a file path as an argument.")
    sys.exit(1)

# Get the file path from the command-line argument
file_path = sys.argv[1]

try:
    # Open the file and read its contents
    with open(file_path, "r") as file:
        for i in file:
            line = i.strip()
            factors = factorize(int(line))
            print(
                f"{line}={factors[0] if len(factors) == 1 else factors[1]}*{factors[0]}"
            )
except FileNotFoundError:
    print("File not found.")
    sys.exit(1)
