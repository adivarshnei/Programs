clc
clear all
close all

display('Lab 9')
display('Aim: Generating a Square Wave from sum of Sine Waves of certain Amplitude and Frequencies')


display('')

startTime = 0;
diffTime = 0.01;
endTime = 40;

time = startTime:diffTime:endTime;
ampl = 1;
freq = 1 / 10;

iterations = 100;

sqw = zeros(size(time));

for n = 1:iterations
    x = 4 * (ampl / (2 * n - 1)) * sin((2 * n - 1) * 2 * pi * freq * time);
    sqw = sqw + x;
end

plot(time,sqw,'--','linewidth',1,'color','k')
title('Plot of square wave formed by addition of odd harmonics of 4*sin(2*pi*(1/10)*t)')
xlabel('Time')
ylabel('Square Wave')
legend('100 iterations');
figure