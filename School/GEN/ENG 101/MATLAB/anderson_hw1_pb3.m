%% Homework problem 3 a,b,c.
% Nolan Anderson
% ENG 101
% 2/4/2019
clear 
clc
close all

%% Functions
x = linspace(-1,1,50);

y1 = (sin(2*pi*x))./(1+x.^2);

y2 = 1./(1+(x.^2));

y3 = (-1)./(1+x.^2);

%% Plotting functions
plot(x,y1, 'b-');
hold on
plot(x,y2, 'r--');
hold on
plot(x,y3, 'g--');

%% Plot labeling
legend({'y1', 'y2', 'y3'}, 'Location', 'southwest')
title('Graph of the 3 functions y1, y2, y3')
xlabel('-1 <= x <= 1')
ylabel('Values for y1, y2, y3')
