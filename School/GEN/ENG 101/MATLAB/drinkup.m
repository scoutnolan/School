%% Assignment day 3 Drinks and Heat Transfer Analysis
% Nolan Anderson
% ENG 101
% 1/16/19

%% Qeustions Part A

temp_drinks = input('What is the temperature of the drinks right now? ')
temp_fridge = input('What is the temperature of the fridge? ')
temp_drinkable = input('What temperature would you like the drinks to be? ')

%% Calculating time to cool part B
k=.35;

timestep1 = ((temp_drinkable) - (temp_fridge))/(temp_drinks - temp_fridge); % 'Time' before taking the natural log
timestep2 = log(timestep1); % 'Time' after taking natural log
timefinal = timestep2/-k    % Final time after dividing by constant k. First two steps were working through the equation.


%% Output for final time Part D

fprintf('It should take around %f minutes for your drinks to cool from %g degrees F to %x degrees F.', timefinal, temp_drinks, temp_drinkable)

%% Vector for time Part E

time_vector = [0 : 5 : 2*timefinal]; % The vector for time it takes for the dirnks to cool
 % Makes the vector a decending function as opposed to a ascending vector.
y = temp_fridge + (temp_drinks-temp_fridge)*exp(-.35*timefinal) % Vector for the starting temp ending with the final temp
plot(time_vector,y, 'rd') % Plots the 2 vectors with red and diamond 
title('Time vs. Temperature of drinks') % Title of the plot
xlabel('Time') % Names the x - axis time
ylabel('Temperature in degrees Farenheit') % Names the y - axis Temperature of drink.
