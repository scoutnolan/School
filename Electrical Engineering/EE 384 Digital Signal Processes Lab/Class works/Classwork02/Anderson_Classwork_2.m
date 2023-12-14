%% Nolan Anderson
% EE 384 
% Classwork 2
% Due 5 September 2021

%% Problem 1

% 1a
clf; close; clear; clc;
x = importdata('SAMPLE_ECG.mat');
t = linspace(1, 2000, length(x));
y = filter([0,1,2], 3, x);

subplot(2, 2, 1), plot(t, x), axis([0 2000 100 220]);
title('ECG.mat'), xlabel('n'), ylabel('x(n)');
subplot(2, 2, 2), plot(t, y), axis([0 2000 100 220]);
title('Problem 1.a'), xlabel('n'), ylabel('y(n)');

% 1b
ty = linspace(1, 2000+2, length(x)+2); 
h = [1/3, 1/3, 1/3]; 
y = conv(x, h);
subplot(2, 2, 3);
plot(ty, y); axis([0 2000 100 220]);
title('Problem 1.b'), xlabel('n'), ylabel('y(n)');
% This is the same result as 1.a

% 1c
% +2 is needed for increased size due to convolution
ty = linspace(1, 2000+2, length(x)+2); 
n = length(x); m = length(h);
n_y = n + m -1;
y = zeros(1,n_y);

for i = 1:n
    for k = 1:m
       y(i+k-1) = y(i+k-1) + h(k)*x(i);
    end
end

subplot(2, 2, 4);
plot(ty, y);
axis([0 2000 100 220]);
title('Problem 1.c'), xlabel('n'), ylabel('y(n)');
 
%% Problem 2

% 2.a
fs = 50; f1 = 10; t = 0:1/fs:1;
y1 = sin(2*pi*f1.*t); 
plot(t, y1), xlabel('t'), ylabel('y1(t)'), title('Problem 2.a');

% 2b
f2 = 60; 
y2 = sin(2*pi*f2.*t);
plot(t, y2), xlabel('t'), ylabel('y2(t)'), title('Problem 2.b');

% 2c
subplot(2, 1, 1);
plot(t, y1), xlabel('t'), ylabel('y1(t)'), title('Problem 2.a');
subplot(2, 1, 2);
plot(t, y2), xlabel('t'), ylabel('y2(t)'), title('Problem 2.b');

% the graphs are identical

%% Problem 3

% 3.a
clf; clear; clc;
f1 = 2000; fs = 50000; % 2 kHz / 50 kHz
t = 0:1/fs:0.01;
y1 = sin(2*pi*f1.*t); subplot(2,2,1);
plot(t, y1), xlabel('t'), ylabel('y(t)'), title('Problem 3.a');
sound(y1, fs); pause(1); 

% 3b
f2 = 6000; % 6 kHz
y2 = sin(2*pi*f2.*t); subplot(2,2,2);
plot(t, y2), xlabel('t'), ylabel('y(t)'), title('Problem 3.b');
sound(y2, fs); pause(1); 
% This sound (y2) is a higher pitch than y1.

% 3c
f3 = 25000; % 25 kHz
y3 = sin(2*pi*f3.*t); subplot(2,2,[3,4]);
plot(t, y3), xlabel('t'), ylabel('y(t)'), title('Problem 3.c');
sound(y3, fs);

% No.. Humans can't hear above 20khz. 