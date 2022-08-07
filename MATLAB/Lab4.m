clc
clear all

display('Lab 4')
display('Aim: (A) Evaluate a given expression and rounding it to the nerest integer value using round, ceil, floor and fixed functions.')
display('(B) Trigonometric functions ex- sin, cos, tan, cosec, cot, sec.')
display('(C) Logarithmic function')
display('(D) Square Root')


% (A)
display('')

matrixLowerLim = -5;
matrixUpperLim = 5;

initMatrix = matrixLowerLim + (matrixUpperLim - matrixLowerLim) * rand(5, 5)
roundMatrix = round(initMatrix)
ceilMatrix = ceil(initMatrix)
floorMatrix = floor(initMatrix)
fixMatrix = fix(initMatrix)


% (B)
timestep = 0.0004;
ampl = 8;
freq = 5;
time = 0 : timestep : 1;
x1 = ampl * cos (2 * pi * freq * time);
x2 = ampl * sin (2 * pi * freq * time);
x3 = ampl * tan (2 * pi * freq * time);
x4 = ampl * cot (2 * pi * freq * time);
x5 = ampl * sec (2 * pi * freq * time);
x6 = ampl * csc (2 * pi * freq * time);

display('y = cos(x)')
plot(time, x1)
ylim([-4 * ampl, 4 * ampl])
figure

display('y = sin(x)')
plot(time, x2)
ylim([-4 * ampl, 4 * ampl])
figure

display('y = tan(x)')
plot(time, x3)
ylim([-4 * ampl, 4 * ampl])
figure

display('y = cot(x)')
plot(time, x4)
ylim([-4 * ampl, 4 * ampl])
figure

display('y = sec(x)')
plot(time, x5)
ylim([-4 * ampl, 4 * ampl])
figure

display('y = csc(x)')
plot(time, x6)
ylim([-4 * ampl, 4 * ampl])
figure


% (C) & (D)
display('')

fxnLowerLim = 0;
fxnUpperLim = 20;
input = fxnLowerLim + (fxnUpperLim - fxnLowerLim) * rand(5, 5)

display('ln(input) = ')
lnMatrix = log(input)

display('log10(input) = ')
log10Matrix = log10(input)

display('sqrt(input) = ')
sqrtMatrix = sqrt(input)