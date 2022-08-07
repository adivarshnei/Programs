clc
clear all

display('Lab 3')
display('Aim: Generating a set of commands on a given vector (Example: X = [1 8 3 9 0 1]) to ')
display('(A) Add up the values of the elements (Check with sum)')
display('(B) Compute the Running Sum (Check with sum), where Running Sum for element j = the sum of elements from i to j inclusive.')
display('Also Generating a Random Sequence using rand() / randn() functions and plotting them')

display('')
display('Declared matrix: ')
matrix = [2, 4, 5;
          2, 7, 8;
          3, 4, 2]

matrixColSum = sum(matrix, 1) % 1 is default, can be omitted
matrixRowSum = sum(matrix, 2)

matrixColCumsum = cumsum(matrix, 1) % 1 is default, can be omitted
matrixRowCumsum = cumsum(matrix, 2)

plot(matrix)
figure

display('')
display('Matrix generated using magic(): ')
magicMatrix = magic(3)

magicMatrixColSum = sum(magicMatrix, 1) % 1 is default, can be omitted
magicMatrixRowSum = sum(magicMatrix, 2)

magicMatrixColCumsum = cumsum(magicMatrix, 1) % 1 is default, can be omitted
magicMatrixRowCumsum = cumsum(magicMatrix, 2)

plot(magicMatrix)
figure

randMatrix = rand(4, 6) % Uniform distribution of random numbers

randMatrixColSum = sum(randMatrix, 1) % 1 is default, can be omitted
randMatrixRowSum = sum(randMatrix, 2)

randMatrixColCumsum = cumsum(randMatrix, 1) % 1 is default, can be omitted
randMatrixRowCumsum = cumsum(randMatrix, 2)

plot(randMatrix)
figure

randNMatrix = randn(3, 2) % Normal distribution of random numbers

randNMatrixColSum = sum(randNMatrix, 1) % 1 is default, can be omitted
randNMatrixRowSum = sum(randNMatrix, 2)

randNMatrixColCumsum = cumsum(randNMatrix, 1) % 1 is default, can be omitted
randNMatrixRowCumsum = cumsum(randNMatrix, 2)

plot(randNMatrix)
figure

randIMatrix = randi(50, 5, 3) % Uniformly distributed pseudorandom integers

randIMatrixColSum = sum(randIMatrix, 1) % 1 is default, can be omitted
randIMatrixRowSum = sum(randIMatrix, 2)

randIMatrixColCumsum = cumsum(randIMatrix, 1) % 1 is default, can be omitted
randIMatrixRowCumsum = cumsum(randIMatrix, 2)

plot(randIMatrix)
figure

randPermMatrix = randperm(6, 6) % Random permutation of integers

randPermMatrixColSum = sum(randPermMatrix, 1) % 1 is default, can be omitted
randPermMatrixRowSum = sum(randPermMatrix, 2)

randPermMatrixColCumsum = cumsum(randPermMatrix, 1) % 1 is default, can be omitted
randPermMatrixRowCumsum = cumsum(randPermMatrix, 2)

plot(randPermMatrix)
figure