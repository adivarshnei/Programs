clc
clear all
close all

display('Lab 6')
display('Aim: Generating a Sinusoidal Signal of a given frequency (say, 100 Hz) and Plotting with graphical Enhancements - Tilting, Labelling, Adding Text, Adding Legends, Adding New Plots to Existing Plot, Printing Text in Greek Letters, Plotting as Multiple and Subplot')


%Set-Up Data
display('')
step = 0.04;
ampl1 = 1;
ampl2 = 2;
ampl3 = 3;
ampl4 = 3;
freq1 = 1;
freq2 = 1;
freq3 = 3;
freq4 = 2;
lowerlim = -5;
upperlim = 5;
x = lowerlim : step : upperlim;
xaxis = zeros(upperlim - lowerlim);
y1 = ampl1 * sin(freq1 * x);
y2 = ampl2 * sin(freq2 * x);
y3 = ampl3 * sin(freq3 * x);
y4 = ampl4 * cos(freq4 * x);


display('')
display('Figure 1')
plot(x,y1)
xlim([lowerlim,upperlim])
ylim([-2 * ampl3,2 * ampl3])
title('Plot of y = sin(x)')
xlabel('x')
ylabel('y = sin(x)')
legend('y = sin(x)');
line([0,0],ylim,'color','k','linestyle','--');
line(xlim,[0,0],'color','k','linestyle','--');
text(pi/2-0.2,1.2,'sin(\pi/2)','fontsize',8);
figure


display('')
display('Figure 2')
plot(x, y2,'--+m','linewidth',2,'Markersize',1)
xlim([lowerlim,upperlim])
ylim([-2 * ampl3,2 * ampl3])
title('Plot of y = 2sin(x)')
xlabel('x')
ylabel('y = 2sin(x)')
legend('y = 2sin(x)');
line([0,0],ylim,'color','k','linestyle','--')
line(xlim,[0,0],'color','k','linestyle','--')
text(pi/2-0.2,2.2,'2sin(\pi/2)','fontsize',8);
figure


display('')
display('Figure 3')
plot(x,y3,'--rs','linewidth',2,'Markeredgecolor','g','Markerfacecolor','b','Markersize',1)
xlim([lowerlim,upperlim])
ylim([-2 * ampl3,2 * ampl3])
title('Plot of y = 3sin(3x)')
xlabel('x')
ylabel('y = 3sin(3x)')
legend('y = 3sin(3x)');
line([0,0],ylim,'color','k','linestyle','--')
line(xlim,[0,0],'color','k','linestyle','--')
text(pi/6-0.2,3.3,'3sin(\pi/6)','fontsize',8);
figure


display('')
display('Figure 4')
plot(x,y4,'o','Markersize',1,'Markeredgecolor','b','Markerfacecolor','y')
xlim([lowerlim,upperlim])
ylim([-2 * ampl3,2 * ampl3])
title('Plot of y = 3cos(2x)')
xlabel('x')
ylabel('y = 3cos(2x))')
legend('y = 3cos(2x)');
line([0,0],ylim,'color','k','linestyle','--')
line(xlim,[0,0],'color','k','linestyle','--')
text(-0.6,3.3,'3cos(0)','fontsize',8);
figure


display('')
display('Combined Figure')
hold all
plot(x,y1)
xlim([lowerlim,upperlim])
ylim([-2 * ampl3,2 * ampl3])
title('Plots of sinusoidal functions')
xlabel('x')
ylabel('y = f(x)')
legend('y = sin(x)');


plot(x, y2,'--+m','linewidth',2,'Markersize',1)
title('Plots of sinusoidal functions')
xlabel('x')
ylabel('y = f(x)')
legend('y = 2sin(x)');


plot(x,y3,'--rs','linewidth',2,'Markeredgecolor','g','Markerfacecolor','b','Markersize',1)
title('Plots of sinusoidal functions')
xlabel('x')
ylabel('y = f(x)')
legend('y = 3sin(3x)');


plot(x,y4,'o','Markersize',1,'Markeredgecolor','b','Markerfacecolor','y')
title('Plots of sinusoidal functions')
xlabel('x')
ylabel('y = f(x)')
legend('y = 3cos(2x)');

text(pi/2-0.2,1.2,'sin(\pi/2)','fontsize',8);
text(pi/2-0.2,2.2,'2sin(\pi/2)','fontsize',8);
text(pi/6-0.2,3.3,'3sin(\pi/6)','fontsize',8);
text(-0.6,3.3,'3cos(0)','fontsize',8);

legend('y = sin(x)','y = 2sin(x)','y = 3sin(3x)','y = 3cos(2x)');

line([0,0],ylim,'color','k','linestyle','--')
line(xlim,[0,0],'color','k','linestyle','--')