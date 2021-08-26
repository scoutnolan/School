% Homework problem 2
% Nolan Anderson
% ENG 101 
% 2/4/2019

clc;
clear;
format bank;

p=110000;
r=4.25/100;
y=[15 30];
M=p*(r/12)./(1-(1+r/12).^(-12.*y));


M_1 = p*(1+r/12).^(12*y);
M_2 = M_1-p;
for n = 1
    fprintf('This is monthly payment with a %d year loan: $%f | $%f | $%f\n', y(n), M(n), M_1(n), M_2(n))
end
for n=2
    fprintf('This is monthly payment with a %d year loan: $%f | $%f | $%f\n', y(n), M(n), M_1(n), M_2(n))
end


