% Homework problem 2
% Nolan Anderson
% ENG 101 
% 2/4/2019

clc;
clear;


p=110000;
r=4.25/100;
y=[15 30];
M=p*(r/12)./(1-(1+r/12).^(-12.*y));


