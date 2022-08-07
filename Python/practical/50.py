# Write a program to display smallest and largest element in 3x4 matrix

def matrixInput(size):
    matrix = []
    submatrix = []
    
    for i in range(size[0]):
        for j in range(size[1]):
            element = int(input(f"Enter Element ({i}, {j}): "))
            submatrix.append(element)
        
        matrix.append(submatrix)
        submatrix = []
    
    return matrix

def elementFinder(size, matrix):
    small = matrix[0][0]
    large = matrix[0][0]
    
    for i in range(size[0]):
        for j in range(size[1]):
            if matrix[i][j] < small:
                small = matrix[i][j]
            if matrix[i][j] > large:
                large = matrix[j][i]
    
    return small, large

size = [3, 4]

print("Matrix: ")
matrix = matrixInput(size)

smallElem, largeElem = elementFinder(size, matrix)

print(f"Smallest element in matrix: {smallElem}")
print(f"Largest element in matrix: {largeElem}")