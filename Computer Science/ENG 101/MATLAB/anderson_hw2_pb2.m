%% Shortest distance to Origin
% Nolan Anderson
% ENG101
% 2/20/2019




minD = inf;
t = 0;
%% Calculation
for t = linspace(1,4,20) % for each value in t, perform this code.
    x = 5.*(t)-10; % Function for x
    y = 25.*t.^2-120.*t+144; % Function for y
    distancefrom00 = sqrt(x^2 + y^2); % Finds distance at each value of t
    if distancefrom00 < minD % once it finds the smallest distance, perform this
        minD = distancefrom00; % assign this distance to the minD (smallest distance) variable.
        time = t;  % assings the lowest t value found by plugging in to the equations to time.
    end
end

%% Output
fprintf('The minimum distance of %.2f occurs at %.3f units of time and (%d,%d)\n', minD, time, x, y);