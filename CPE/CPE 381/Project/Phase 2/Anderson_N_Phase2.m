%% Project Phase 2
% Nolan Anderson
% CPE 381
% Dr. Jovanov

clear
clc

[signal, Fs] = audioread('Anderson_N_filt.wav');
figure(1);
plot(signal);
title("Plot of Modified WAV file from Phase 1");

yleft = signal(:,1); % left channel
yright = signal(:,2); % right channel

% Left channel period sorting
voice = signal(1:10*Fs,1); 
noise = signal(10*Fs:length(signal(:,1)),1); 

figure(2);
plot(voice);
title("t < 10s");

figure(3);
plot(noise);
title("t > 10s");