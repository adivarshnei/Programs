clc
clear all

display('Lab 5')
display('Aim: (A) To create a vector X with elements X = (-1)^(n+1)/(2n-1) and add the 100 elements.')
display('(B) Plot x, x^3, exp(x), exp(x^3)')


%(A)
display('')
n = 0 : 100;
X = (power(-1, n+1) ./ (2 * n - 1));

display('Summation of X = (-1)^(n+1)/(2n-1)')
Xsum = sum(X)

display('Sum plot')
plot(n, Xsum)
figure

%(B)
display('')
x = 0 : 4;
f1 = x;
f2 = power(x, 3);
f3 = exp(x);
f4 = exp(power(x, 3));

display('Plot of x')
plot(x, f1)
figure

display('Plot of x^3')
plot(x, f2)
figure

display('Plot of exp(x)')
plot(x, f3)
figure

display('Plot of exp(x^3)')
plot(x, f4)
figure