%% Right Triangle / Combinatorics
% Nolan Anderson
% ENG 101
% 1/9/2019
% MATLABR2018b

%% Assignment 1 Part 1

% Triangle problem

%% Given Triangle Variables

a = 15; %cm
c = 42; %cm

% Unknowns the following program finds:

% Side b
% Angle opposite of side b (B)
% Angle opposite of a (A)

%% Unknown Side 

side_b = sqrt((c^2)-(a^2)) % Variation of the pythagoreom theorem 

%% Angle B and Angle A

% SOHCAHTOA

% To find angle A, use sine.

angle_A = asind(a/c) % a in asind is inverse, and d is degrees

% To find angle B use tangent

angle_B = atand(side_b/a) % a in atand is inverse, and d is degrees

%% Assignment 1 Part 2
% Factorial

% Figuring out how many 3 card combos there are in a deck of 52 cards


myanswer = 1 % Initialization, multiplying by one so you're not getting too big of a number
for index = 50:52 % Using 'f = factorial(52)' does not work because it multiplies all the way down to 1
    myanswer = myanswer * index % Provides same answer as 52*51*50 as last 'myanswer'
end




