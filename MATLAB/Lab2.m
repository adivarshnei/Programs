clc
clear all

display('Lab 2')
display('Aim: Performing Matrix Manipulations - Concatenating, Indexing, Sorting, Resizing and Flipping about a Vertical Axis/Horizontal Axis: Creating Arrays X & Y of given size (1 X N) and Performing: ')
display('(A) Relational Operations: >, <, ==, <=, >=, ~=')
display('(B) Logical Operations: ~, &, |, XOR')

% Matrices
inputMatrix1 = [0, 9, 0, 4, 6, 8, 0]
inputMatrix2 = [0, 1, 3, 5, 0, 2, 4]

% Magic Function
magicMatrix_3 = magic(3)
magicMatrix_4 = magic(4)
magicMatrix_5 = magic(5)

% Concatenating
display('Concatenation')
horzConcat = horzcat(inputMatrix1, inputMatrix2)
vertConcat = vertcat(inputMatrix1, inputMatrix2)

% Indexing
display('Indexing')
magicMatrix_5(1,3)
magicMatrix_5(2:4,1:2)
magicMatrix_5(1,:)
magicMatrix_5(:,end)

% Sorting
sortedAsc = sort(inputMatrix1)
sortedDsc = sort(inputMatrix1, 'descend')

display('')
display('Unsorted array:')
display(inputMatrix1)

display('Sorted array (Ascending):')
display(sortedAsc)

display('Sorted array (Descending):')
display(sortedDsc)

% Reshape Function
display('Reshaping')
reshapedMatrix_4_1 = reshape(magicMatrix_4, 8, 2)
reshapedMatrix_4_2 = reshape(magicMatrix_4, [], 8)

% Flip Function
display('Flipping')
flippedMatrixLR_3 = fliplr(magicMatrix_3)
flippedMatrixUD_3 = flipud(magicMatrix_3)

% Relational Operations
display('(A) Relational Operations')
display('inputMatrix1 > inputMatrix2')
display(inputMatrix1 > inputMatrix2)

display('inputMatrix1 < inputMatrix2')
display(inputMatrix1 < inputMatrix2)

display('inputMatrix1 == inputMatrix2')
display(inputMatrix1 == inputMatrix2)

display('inputMatrix1 <= inputMatrix2')
display(inputMatrix1 <= inputMatrix2)

display('inputMatrix1 >= inputMatrix2')
display(inputMatrix1 >= inputMatrix2)

display('inputMatrix1 ~= inputMatrix2')
display(inputMatrix1 ~= inputMatrix2)

% Logical Operations
display('(B) Logical Operations')
display('Original Arrays: ')
display(inputMatrix1)
display(inputMatrix2)

display('~inputMatrix1')
display(not(inputMatrix1))

display('inputMatrix1 & inputMatrix2')
display(and(inputMatrix1, inputMatrix2))

display('inputMatrix1 | inputMatrix2')
display(or(inputMatrix1, inputMatrix2))

display('inputMatrix1 XOR inputMatrix2')
display(xor(inputMatrix1, inputMatrix2))