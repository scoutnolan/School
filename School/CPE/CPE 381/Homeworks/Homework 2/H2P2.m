%% Effect of multipath
A = 1;
f = 400;
Fs = 11025;         % Sampling frequency, 11,025Hz
Ts = 1/Fs;           % Sampling interval
t = 0:Ts:3;         % Time 
x = exp(-t).*sin(2*pi*f.*t);
N = length(t);

%% Signal delays
%This is the (t-0.2) portion.
delay = 0.2*Fs;             
delay2 = 0.4*Fs;
intdelay = round(0.2*Fs);       % integer delay, based on sampling frequency.
intdelay2 = round(0.4*Fs);      % second integer delay.   
y1 = [zeros(1, intdelay) x(1:N-intdelay)];      % Delayed signal
y2 = [zeros(1, intdelay2) x(1:N-intdelay2)];    % Delayed signal

%% Signal and plot
y = x + 0.4*y1 + 0.2*y2;  
% plot the function
plot(t,y),title('y=x+0.4*y1+0.2*y2'),xlabel('time[s]')
% and listen the result
sound(y,Fs);