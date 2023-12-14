%% Homework Problem 2 Part C
% Nolan Anderson
% ENG 101
% 2/4/2019
clear;
clc;
close all;

%% Variables
h = input('Total cost of the house:  ');
p = input('Downpayment on the house:  ');
r = input('Interest rate in percent form:  ');
y = input('How many years for the loan:  ');

%% Calculations
P = h-p; %Finds principal payment
r = r/100;
M=P*(r/12)./(1-(1+r/12).^(-12*y)); % Monthly payment
A = P*(1+r/12).^(12*y); % Total cost with loan
K = A-P; % Difference in loan - not a loan

%% Outputs
fprintf('Your monthly payment is $%.2f for %d months\n', M, y.*12);
fprintf('You will have to pay this much more by taking out a loan: $%.2f\n', K)
