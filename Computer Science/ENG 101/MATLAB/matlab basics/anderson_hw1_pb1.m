%% Homework 1 Problem 1
% Nolan Anderson
% Eng 101
% 2/4/2019

clear;
clc;
close all;
%% Vairables
ta = input('What is the current air temperature?  ');
fprintf('\n')
v = input('What is the current wind speed in miles per hour?   ');

%% Calculations
twc = 35.74 + 0.6215*ta-35.75*(v^.16)+0.4275*ta*(v^.16); % Equation for wind chill
difftemp = ta-twc; %Finds the difference in the outside temp and the wind chill

%% Output Statements
fprintf('\n')
fprintf('The wind chill is %f degrees Fahrenheit\n\n', twc);
fprintf('It feels %f colder than the actual air temperature\n\n', difftemp);
q1 = input('Is it cold outside for you? [Yes/No]  ', 's');
fprintf('\n')
if strcmp(q1, 'Yes') % strcmp(x,'s') compares strings to a variable, allowing the matricies to be equal.
    disp('Well, dress warmly')
elseif (q1)
    disp('Do not dress warmly')
end