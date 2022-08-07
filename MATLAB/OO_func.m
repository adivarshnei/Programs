inputSignal = [0 0 0];

function PlotGraphs(inputSignal, inputThreshold)
display('')
ampl1 = inputSignal(1); %1
freq1 = inputSignal(2); %2
sampling = inputSignal(3); %100
threshold = inputThreshold; %0.4

timePd = 1/freq1;
lowerlim = 0;
upperlim = 2*timePd;
timeDiff = 1/sampling;

x = lowerlim:timeDiff:upperlim;
y1 = ampl1 * sin(2 * pi * freq1 * x);
y2 = zeros(length(y1),1);
y3 = zeros(length(y1),1);

for f=1:length(y1)
    if (y1(f) >= threshold)
        y3(f) = y1(f);
    else
        y3(f) = threshold;
    end
    
    if (y1(f) >= 0)
        y2(f) = y1(f);
    else
        y2(f) = 0;
    end
end

plot(x,y1,'color','r')
xlim([lowerlim,upperlim])
ylim([-ampl1,ampl1])
xlabel('Time(s)')
title("Input Waveform")
grid on
figure

plot(x,y2,'color','r')
xlim([lowerlim,upperlim])
ylim([-ampl1,ampl1])
xlabel('Time(s)')
title("Half-Rectified Wave")
grid on
figure

plot(x,y3,'color','b')
xlim([lowerlim,upperlim])
ylim([-ampl1,ampl1])
xlabel('Time(s)')
title("Wave Rectified According to Threshold")
grid on
figure

end

%PlotGraphs(inputAmp, inputFreq, inputSampling, inputThreshold)