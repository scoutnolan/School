%% Assignment day 3 Drinks and Heat Transfer Analysis
% Nolan Anderson
% ENG 101
% 1/16/19

%% Qeustions

temp_drinks = input('What is the temperature of the drinks right now? ')
temp_fridge = input('What is the temperature of the fridge? ')
temp_drinkable = input('What temperature would you like the drinks to be? ')


%% Time calculation
% Tc = Tr+(Ti-Tr)e^(-kt)
% k = .35
% Tc = final temp
% Tr = temp of surroundings
% Ti = starting temp
% k = cooling constant
% t = time
% Variable k:
k = -.35
%% Calculating time to cool
timestep1 = ((temp_drinkable) - (temp_fridge))/(temp_drinks - temp_fridge) % 'Time' before taking the natural log
timestep2 = log(timestep1) % 'Time' after taking natural log
timefinal = timestep2/k    % Final time after dividing by constant k. First two steps were working through the equation.

%% Output for final time

fprintf('It should take around %f minutes for your drinks to cool from %g degrees F to %x degrees F.', timefinal, temp_drinks, temp_drinkable)

%% Vector for time

time_vector = linspace(0,2.*timefinal,20);
plot(time_vector, 'rd')

title('Time vs. Temperature of drinks')
xlabel('Time')
ylabel('Temperature of drink')

