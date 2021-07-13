%% Header
% Nolan Anderson
% CPE 381 Final Exam
% Final.m
% Plots the spectrum using a hanning function and input .mat file. 

%% Load and initialize
load('fintest.mat');

Fs = 200; %sampling frequency
NFFT = 1024; %NFFT
H = 1024; %Hanning window size
Window = transpose(hann(H));

%% Calculate and Plot
x = x .* Window;

out = fft(x, NFFT);
f = Fs*(0:(NFFT/2))/NFFT; % Half samp freq. 

sp2 = abs(out / NFFT);
sp1 = sp2(1:NFFT/2+1);
sp1(2:end-1) = 2*sp1(2:end-1);

plot(f,sp1)