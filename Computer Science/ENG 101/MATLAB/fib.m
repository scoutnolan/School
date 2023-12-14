%% Fibonacci 100th element
% Nolan Anderson
% ENG 101
% 1/30/2019
clear
clc


x = 1;
y = 1;
for i = 3:100 %sets a limit on where the for loop should stop
    % starting at 3 because C = A+B is finds the 3rd element already.
    x = y; % assigns x to y because every time you add you're changing which number you last added to.
    z = x+y; % actual formula for fibonacci after assigning numbers to each other.
    y = z;
end

disp(z)