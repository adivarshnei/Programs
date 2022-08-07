# Write a program to accept two matrices and subtract them

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

def matrixMul(size, matrixA, matrixB):
    resMatrix1 = [[0 for i in range(size)] for j in range(size)]
    resMatrix2 = [[0 for i in range(size)] for j in range(size)]
    
    for i in range(size):
        for j in range(size):
            for k in range(size):
                resMatrix1[i][j] = resMatrix1[i][j] + (matrixA[i][k] * matrixB[k][j])
                resMatrix2[i][j] = resMatrix2[i][j] + (matrixB[i][k] * matrixA[k][j])
    
    return resMatrix1, resMatrix2

size = int(input("Enter the size of the matrices: "))

print("Matrix A: ")
matrixA = matrixInput(size)

print("Matrix B: ")
matrixB = matrixInput(size)

resMatrix1, resMatrix2 = matrixMul(size, matrixA, matrixB)

print ("A * B = ")

for i in range(size):
    for j in range(size):
        print(f"{resMatrix1[i][j]}\t", end = '')
    
    print()

print ("B * A = ")

for i in range(size):
    for j in range(size):
        print(f"{resMatrix2[i][j]}\t", end = '')
    
    print()