function [y] = myline(m,b,xmin,xmax)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

x = linspace(xmin,xmax,100);

y = m*x + b;
plot(x,y);
end

