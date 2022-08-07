# Write a program to accept two matrices and add them

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

def matrixAdd(size, matrixA, matrixB):
    resMatrix = []
    submatrix = []
    
    for i in range(size):
        for j in range(size):
            element = matrixA[i][j] + matrixB[i][j]
            submatrix.append(element)
        
        resMatrix.append(submatrix)
        submatrix = []
    
    return resMatrix

size = int(input("Enter the size of the matrices: "))

print("Matrix A: ")
matrixA = matrixInput(size)

print("Matrix B: ")
matrixB = matrixInput(size)

resMatrix = matrixAdd(size, matrixA, matrixB)

print ("A + B = ")

for i in range(size):
    for j in range(size):
        print(f"{resMatrix[i][j]}\t", end = '')
    
    print()