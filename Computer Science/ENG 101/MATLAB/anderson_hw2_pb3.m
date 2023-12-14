%% Unit conversion 
% Nolan Anderson
% ENG 101
% 2/20/2019


%% Input Statements
data1 = input('Please select your first unit type 1 = Cubic Meters, 2 = Cubic Feet, 3 = Liters, 4 = US Gallons \n'); % First step of the conversion
numeric = input('How much of the first unit do you have? ' ); % How much of the first unit the user has
data2 = input('What would you like to convert to? 1 = Cubic Meters, 2 = Cubic Feet, 3 = Liters, 4 = US Gallons \n'); % What the user is converting to


%% If statements
if data1 ~= data2
    
    if data1 == 1 && data2 == 2 % Cubic meters to Cubic feet
        conversion = numeric * 35.3147;
        fprintf('You have %.2f cubic feet\n', conversion)
    end
    
    if data1 == 1 && data2 == 3 % Cubic meters to Liters
        conversion = numeric * 1000;
        fprintf('You have %.2f Liters\n', conversion)
    end
    
    if data1 == 1 && data2 ==4 % Cubic meters to US Gallons
        conversion = numeric * 264.172;
        fprintf('You have %.2f US Gallons\n', conversion)
    end
    
    if data1 == 2 && data2 == 1% Cubic Feet to Cubic meters
        conversion = numeric / 35.3147;
        fprintf('You have %.2f Cubic Meters', conversion)
    end
    
    if data1 == 2 && data2 == 3 % Cubic Feet to Liters
        conversion = numeric * 28.3168;
        fprintf('You have %.2f Liters', conversion)
    end
    
    if data1 == 2 && data2 == 4 % Cubic feet to US Gallons
        conversion = numeric * 7.481;
        fprintf('You have %.2f US Gallons', conversion)
    end
    
    if data1 == 3 && data2 == 1 % Liters to Cubic meters
        conversion = numeric / 1000;
        fprintf('You have %.2f Cubic Meters', conversion)
    end
    
    if data1 == 3 && data2 == 2 % Liters to Cubic Feet
        conversion = numeric / 28.317;
        fprintf('You have %.2f Cubic Feet', conversion)
    end
    
    if data1 == 3 && data2 == 4 % Liters to US Gallons
        conversion = numeric / 3.785;
        fprintf('You have %.2f US Gallons', conversion)
    end
    
    if data1 == 4 && data2 == 1 % US Gallons to Cubic Meters
        conversion = numeric / 264.172;
        fprintf('You have %.2f Cubic Meters', conversion)
    end
    
    if data1 == 4 && data2 == 2 % US Gallons to Cubic meters
        conversion = numeric / 7.481;
        fprintf('You have %.2f Cubic Feet', conversion)
    end
    
    if data1 == 3 && data2 == 3 %US Gallons to Liters
        conversion = numeric * 3.785;
        fprintf('You have %.2f Liters', conversion)
    end
end

if data1 > 4 || data2 > 4 || data1 == data2 % This cancels the code if the input for unit type is greater than 4 or if the data inputs are the same
    disp('This is not a valid conversion');
    return;
end


