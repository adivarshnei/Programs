clear all
close all

inputAmp = input("Enter the wave amplitude: ");
inputFreq = input("Enter the freqency: ");
inputSampling = input("Enter the sampling: ");
inputThreshold = input("Enter the threshold: ");

inputSignal = [inputAmp, inputFreq, inputSampling];

source("OO_func.m")

PlotGraphs([inputAmp, inputFreq, inputSampling], inputThreshold)