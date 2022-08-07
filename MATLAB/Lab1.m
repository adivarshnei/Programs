clc;
clear all;

display('Lab 1');
display('Aim: Creating a One and Two-Dimensional Array (Row/Column Vector) (Matrix of Given Size) and:')
display('(A) Performing Arithmetic Operations - Addition, Subtraction, Multiplication and Exponentiation')
display('(B) Performing Matrix Operations - Inverse, Transpose, Rank')
display('')   % Used to insert blank lines in output


% Creating One Dimensional Array
a = [5 10 15 20 25]
b = [1; 
     2; 
     3; 
     4;
     5]
x = [7, 8, 9, 10, 11]
y = [1, 2, 3; 
     4, 5, 6;
     7, 8, 9]

% Creating Multi Dimensional Array
c = [ 7, 6,  2; 
     12, 5,  7; 
     10, 4, 19]


% Performing Arithmetic Operations
display('')
display('(A) Arithmetic Operators')
display('')

display('Addition of Matrix')
f = a + x

display('Subtraction of matrix')
g = a - x

display('Multiplication of matrix')
h = a * b

display('')
display('Exponentiation of matrix')   % e ^ (every element of matrix)
ex = exp(a)


% Performing Matrix Operations
display('')
display('(B) Matrix Operations')
display('')

display('Inverse of Matrix')
i = inv(c)

display('Transpose of Matrix')
t = transpose(c)

display('Determinant of Matrix')
d = det(c)

display('')
display("Rank of Matrix")
r = rank(c)