% EE316-08 Spring 2021
% Lab1 Calculation: Solve for I1, I2, and I3 (with the unit of A)
% January 6, 2021

clear all;
close all;
clc;

% Declare variables
tolerance = 0; % percent
[R1, R2, R3] = deal(100 * (tolerance + 100)/100);
[R4, R5] = deal(1000 * (tolerance + 100)/100);
[R6, R7] = deal(2200 * (tolerance + 100)/100);

% Declare the system of equations
syms I1 I2 I3
eqn1 = I1*(R1 + R2 + R6) - I2*R6 - I3*R2 == 5;
eqn2 = -I1*R6 + I2*(R5 + R6 + R7) - I3*R5 == 0;
eqn3 = -I1*R2 - I2*R5 + I3*(R2 + R3 + R4 + R5) == 0;

% Put your system into Matrix and Disply
[A,B] = equationsToMatrix([eqn1, eqn2, eqn3], [I1, I2, I3])

% Solve for I1, I2, and I3 (in the unit of A)
I = linsolve(A, B)
I_A = vpa(I, 5)

% Convert from A to mA
I_mA = vpa(I*10^3, 5)
