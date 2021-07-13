%% Homework Problem 2 Part B
% Nolan Anderson
% ENG 101
% 2/4/2019
clear;
clc;
close all;

%% Variables
r = 4.25/100;
y = [15 30];
dp=0:5000:50000; % Conditions for down payments 
p = 110000 - dp;  % Finds principal amount payed based off of dp

%% Output Statements
fprintf('Principle Amount | 15 Year Payment | 30 Year Payment\n')

for k =1:length(p) % creates an array based on the length of p
    M=p(k)*(r/12)./(1-(1+r/12).^(-12.*y)); %Finds monthly payment for each year
    fprintf(' $%d   |   $%f   |   $%f \n',p(k),M(1),M(2)); % Creates a f statement that keeps going until all conditions are met
end
