%% Input Variables
enemy_health = input('How much health do they have? ');
enemy_shield = input('How much shield do they have? ');
shot_damage = input('How much damage does each shot do?  ');
headshot_damage = input('How much damage does each headshot do? ');
total_health = enemy_shield + enemy_health;

%% Counters
headshot_counter = 0;
shots = 0;
bodyshot_counter = 0;


%% Calculations
while total_health > 0
    headshot = input('Was this a headshot? Y/N ', 's');
    if headshot  == 'Y' || headshot == 'y'
        shots = shots + 1;
        headshot_counter = 1 + headshot_counter;
        total_health = total_health - headshot_damage;
    
    else
        shots = shots + 1;
        bodyshot_counter = bodyshot_counter + 1;
        total_health = total_health - shot_damage;
    end
end







newfunction = @(x,y,z) x.^3 + 3*x + (2/3)*x + 5;
x = -100:0.1:100;
figure(1)
plot(x,newfunction(x))



%% Output
fprintf('It took %g shots to kill your enemy with %g head shots and %g body shots.\n', shots, headshot_counter, bodyshot_counter)

          