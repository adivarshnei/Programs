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

def matrixSub(size, matrixA, matrixB):
    resMatrix1 = []
    resMatrix2 = []
    submatrix1 = []
    submatrix2 = []
    
    for i in range(size):
        for j in range(size):
            element1 = matrixA[i][j] - matrixB[i][j]
            submatrix1.append(element1)
            element2 = matrixB[i][j] - matrixA[i][j]
            submatrix2.append(element2)
        
        resMatrix1.append(submatrix1)
        resMatrix2.append(submatrix2)
        submatrix1 = []
        submatrix2 = []
    
    return resMatrix1, resMatrix2

size = int(input("Enter the size of the matrices: "))

print("Matrix A: ")
matrixA = matrixInput(size)

print("Matrix B: ")
matrixB = matrixInput(size)

resMatrix1, resMatrix2 = matrixSub(size, matrixA, matrixB)

print ("A - B = ")

for i in range(size):
    for j in range(size):
        print(f"{resMatrix1[i][j]}\t", end = '')
    
    print()

print ("B - A = ")

for i in range(size):
    for j in range(size):
        print(f"{resMatrix2[i][j]}\t", end = '')
    
    print()