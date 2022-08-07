clc
clear all
close all

display('Lab 10')
display('Aim: To create Basic 2D and 3D plots: parametric space curve, Polygons with vertices, 3D contour lines and pie and bar charts')


%Plots with linspace
xNorm = linspace(5, 50, 200);
yNorm = exp(sin(xNorm));
plot(xNorm,yNorm,'-o','Markerfacecolor','b','Markersize',1)
title('y = e \^ (sin(x))')
xlabel('x')
ylabel('e \^ (sin(x))')
figure

x = linspace(0, 20, 2000);
y = sin((x .^ (1/2)));
plot(x,y,'color','k','--')
title('y = sin(sqrt(x))')
xlabel('x')
ylabel('sin(sqrt(x))')
figure


%Parametric Space Curve
x3d = cos(x);
y3d = sin(x);
z3d = log(x);
plot3(x3d,y3d,z3d,'linewidth',2)
title('Parametric Plot of x = cos(x), y = sin(x), z = log(x)')
xlabel('cos(x)')
ylabel('sin(x)')
zlabel('log(x)')
figure

%3D Contour Plot
[X,Y] = meshgrid(-5:0.1:5);
Z = sin(X) + cos(Y);
contour3(X,Y,Z,50)
xlabel('x')
ylabel('y')
zlabel('sin(x) + cos(y)')
title('Contour Plot of z = sin(x) + cos(y)')
figure

%Pie Charts
pieX1 = [10 15 20 25 30];
pieLabels1 = {'a','b','c','d','e'};
pie(pieX1, pieLabels1)
title('Sample Pie Chart 1')
figure

pieX2 = [10 30 40 30];
pieLabels2 = {'w','x','y','z'};
pie(pieX2, pieLabels2)
title('Sample Pie Chart 2')
figure

%Bar Charts
barY = [5 2 3; 6 3 1; 9 0 12];
bar(barY)
title('Sample Bar Chart')
figure