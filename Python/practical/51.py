# Write a program to accept a matrix and transpose it

def matrixInput(size):
    matrix = []
    submatrix = []
    
    for i in range(size):
        for j in range(size):
            element = int(input(f"Enter Element ({i}, {j}): "))
            submatrix.append(element)
        
        matrix.append(submatrix)
        submatrix = []
    
    return matrix

def matrixTranspose(size, matrix):
    resMatrix = []
    submatrix = []
    
    for i in range(size):
        for j in range(size):
            element = matrix[j][i]
            submatrix.append(element)
        
        resMatrix.append(submatrix)
        submatrix = []
    
    return resMatrix

size = int(input("Enter the size of the matrices: "))

print("Matrix A: ")
matrix = matrixInput(size)

transMatrix = matrixTranspose(size, matrix)

for i in range(size):
    for j in range(size):
        print(f"{transMatrix[i][j]}\t", end = '')
    
    print()