%% Stock Vectors homework problem 4
% Nolan Anderson
% ENG 101
% 2/4/2019


clear;
close all;
clc;

%% Stocks 
stock1 = [19 18 21 21 25 19 17 21 27 29];
stock2 = [22 14 20 19 24 18 16 25 28 27];
stock3 = [17 13 22 23 19 17 20 21 21 28];

%% Calculations 
format short

a = stock1 > stock2 & stock3;
q1 = nnz(a); % nnz(x) finds the number of non zero values

b = stock1 > stock2|stock3; % Stock one greater than stock 2 or 3
q2 = nnz(b);

c = stock1 > stock2 & stock1 < stock3; % Stock one greater than 2, less than 3
q3 = nnz(c);

%% Output statements based on calculations
fprintf('A) Stock 1 was higher than stocks 2 and 3 for %g days\n', q1)
fprintf('B) Stock 1 was higher than stock 2 OR 3 for %g days\n', q2)
fprintf('C) Stock 1 is higher than stock 2 and less than stock 3 for %g days\n', q3)