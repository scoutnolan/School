%% Homework problem 3 a,b,c.
% Nolan Anderson
% ENG 101
% 2/4/2019
clear; 
clc;
close all;

%% Functions
x = linspace(-1,1,50);

y1 = (sin(2*pi*x))./(1+x.^2);

y2 = 1./(1+(x.^2));

y3 = (-1)./(1+x.^2);

%% Plotting functions
plot(x,y1, 'b-'); % The following plots the graph based on the conditions set by x
hold on
plot(x,y2, 'r--');
hold on
plot(x,y3, 'g--');

%% Plot labeling
legend({'y1', 'y2', 'y3'}, 'Location', 'southwest') % legend and location
title('The functions y1, y2, and y3') % title of graph
xlabel('-1 <= x <= 1') % x axis label
ylabel('Values for y1, y2, y3') % y axis label
