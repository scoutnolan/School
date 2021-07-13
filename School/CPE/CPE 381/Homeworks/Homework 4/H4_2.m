%% Nolan Anderson
% CPE 381 Homework 4 #2

Fs = 20;      
Ts = 1/Fs;     
t = -6:Ts:6;     % Time 
h = sin(pi*t)/(pi*t);
plot(t, h);