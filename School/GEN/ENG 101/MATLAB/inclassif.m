%% Identifying quadtratic roots 

clc
clear

a = input('What is the "a" value in your function?  '); % Inputs for the variables a,b,c
b = input('What is the "b" value in your function?  ');
c = input('What is the "c" value in your function?  ');

delta = (b^2)-(4*a*c); %Finds the root type using inputted variables
d = [a b c];  % Puts the inputs into an array
r = roots(d) % finds the roots of the inputted variables
if delta < 0 % if the roots are less than zero
    fprintf('Your root type is complex and your roots are %g%+gi\n' ,real(r), imag(r))
elseif delta == 0 %if the roots equal 0
    fprintf('Your root type is equal and real and your roots are %g',r)
elseif delta > 0 % if the roots are greater than 0
    fprintf('Your root type is un-equal and real and your roots are %g\n',r)
end


