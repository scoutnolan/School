%% Circumference In Class Assignment
% Nolan Anderson
% 2/5/2019
% ENG 101


clear all;
clc;
close all;

%% Variables
N = input('\nWhat is your value of N? : ');
r=6370; % radius of earth in KM


%% MATLAB pi

c_earth1 = 2*pi*r;
fprintf('\nThe Circumference of the earth using MATLAB pi %3.2f\n', c_earth1) 


%% Leibnitz's Pi Calculation

estimatepi_leib=0; % initial sum value
n=0;
for i=1:N+1 %summation is from 0 -> N, which this sets.
    estimatepi_leib=estimatepi_leib+(((-1)^n)/((2*n)+1)); % perform the summation operation through leibnitz method
    n=n+1;
end
estimate_leib=estimatepi_leib*4; % multiply by 4 to get pi estimations
pi_leib=estimate_leib; % Leibnitz's estimation for pi


% Circumference using Leibnitz's Pi
circ_earth1=2*pi_leib*r; % calculate circumference using formula 2*pi*r

% Output for Leibnitz's method
fprintf('\nValue of pi estimated through Leibnitz method is %3.2f\n',pi_leib);
fprintf('Circumference of earth using Leibnitz''s pi %3.2f\n',circ_earth1);


%% Nilakantha's pi Calculation

sum=0; % where summation starts
n = 0;
for i=1:N+1 % part of the summation equation. n = 0 on the bottom, n+1 on top
    sum=sum+(( (-1)^n ) / (((2*n)+3)^3-(2*n+3))); % pi using nilakantha's method
    n=n+1;
end

% Circumference Using Nilaktha's Method
estimatepi=4*(sum+(3/4)); % add 3/4 and multiply by 4 to get pi estimation
pi_nila=estimatepi; % estimate pi through Leibnitz method
c_nila=2*pi_nila*r; % circumference equation w/ nila's pi

% Output for Nilakatha Method
fprintf('\nValue of pi estimated through Nilakantha method is %3.2f\n',pi_nila);
fprintf('Circumference of earth using Nilakantha''s pi %3.2f\n',c_nila);