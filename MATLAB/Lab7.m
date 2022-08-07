clc
clear all
close all

syms dummyFunc(x)

display('Lab 7')
display('Aim: Solving First Order Differential Equations using Built-in Functions')


display('')
display('Simple function dependent on 2 variables')
syms f1(x, y);
f1(x, y) = e ^ (3 * x) + 2 * (y ^ 2)
f1(1, 3)

display('')
display('Matrix function dependent on 1 variable')
syms f2(x);
M = [exp(x), log(x);
     sin(x), cos(x)];
f2(x) = M
f2(1)

display('')
display('Simple function dependent on 2 variables over a range of values')
syms f3(x, y);
f3(x, y) = log((x ^ 2)) / (y + e ^ y)
f3(5, 1)
xVal = 1 : 2 : 11;
yVal = 3 : 2 : 13;
f3(xVal, yVal)

display('')
display('Simple Derivative on basis of x and y')
xDerivativef3 = diff(f3, x)
yDerivativef3 = diff(f3, y)

display('')
display('Variable replacement')
xDerivativef3(y, (e ^ x))

display('')
display('Solution of an ordinary differential equation with given condition')
syms y(t) a;
equation = diff(y, t) == log(a ^ 3)
condition = y(-3) == 8
ySol(t) = dsolve(equation, condition)

display('')
display('Plot of solution of an ordinary differential equation')
tspan = [-10, 10];
y0 = 0;
[t, y] = ode45(@(t, y) (e ^ t) * (sin(t))^3, tspan, y0);
plot(t,y,'--o','linewidth',1,'Markersize',2,'Markeredgecolor','b','Markerfacecolor','y')
title('Plot of solution of y'' = (exp(t)) * (sin(t))^3')
xlabel('t')
ylabel('y'' = (exp(t)) * (sin(t))^3')
legend('y'' = (exp(t)) * (sin(t))^3');
line([0,0],ylim,'color','k','linestyle','--')
line(xlim,[0,0],'color','k','linestyle','--')
figure