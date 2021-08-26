%% Identifying quadtratic roots 
% Nolan Anderson
% ENG 101
% 1/28/2019

clc
clear

%% Variables
a = input('What is the "a" value in your function?  '); % Inputs for the variables a,b,c
b = input('What is the "b" value in your function?  ');
c = input('What is the "c" value in your function?  ');

%% Functions
delta = (b^2)-(4*a*c); %Finds the root type using inputted variables
d = [a b c];  % Puts the inputs into an array
r = roots(d) % finds the roots of the inputted variables


%% If elseif Statements
if delta < 0 % if the roots are less than zero
    fprintf('Your root type is complex and your roots are %g%+gi\n and %g%+gi\n' ,real(r(1)), imag(r(1)),real(r(2)), imag(r(2))) % real(r(1)) finds the first real value of r, and so on for imag(r(1)) etc.
elseif delta == 0 %if the roots equal 0
    fprintf('Your root type is equal and real and your roots are %g',r) %outputs the root type and the actual roots for the variables
elseif delta > 0 % if the roots are greater than 0
    fprintf('Your root type is un-equal and real and your roots are %g\n',r) %outputs the root type and the actual roots for the variables.
end


