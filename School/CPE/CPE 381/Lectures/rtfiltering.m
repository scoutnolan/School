% rtfilter.m
% Example RT filtering
%
% E. Jovanov
% April 2020
%

%% Init

% Try this example to see effectivness of the 3-point averager 
Fs=9;   % low sampling frequency

% Try this example to see effectivness of the 3-point averager 
%Fs=50;   % high sampling frequency

% init variables
Ts=1/Fs;
t=(1:100).*Ts; % time

f1=3; % Hz
x1=4*sin(2*pi*f1.*t);
f2=1; % Hz
x2=sin(2*pi*f2.*t);
x=x1+x2;

%% Filter
xf=filter([1/3 1/3 1/3],1,x);

%% Visualize

plot(t,x,'b',t,xf,'r')
legend('original','filtered signal'),grid
%stem(t,xf,'r')
