%% Unit conversion 
% Nolan Anderson
% ENG 101
% 2/20/2019

% Cubic meters, cubic feet, liters, US gallons
%% Input Statements
data1 = menu('Please select your first unit type', 'Cubic Meters', 'Cubic Feet', 'Liters', 'US Gallons');
data2 = menu('What would you like to convert to?', 'Cubic Meters', 'Cubic Feet', 'Liters', 'US Gallons');
numeric = input('What is the numeric value for your first choice? ' );
if data1 ~= data2
    
    if data1 == 1 && data2 == 2
        conversion = numeric * 35.3147;
        fprintf('You have %.2f cubic feet\n', conversion)
    end
    if data1 == 1 && data2 == 3
        conversion = numeric * 1000;
        fprintf('You have %.2f Liters\n', conversion)
    end
    if data1 == 1 && data2 ==4
        conversion = numeric * 264.172;
        fprintf('You have %.2f US Gallons\n', conversion)
    end
    if data1 == 2 && data2 == 1
        conversion = numeric / 35.3147;
        fprintf('You have %.2f Cubic Meters', conversion)
    end
    if data1 == 2 && data2 == 3
        conversion = numeric * 28.3168;
        fprintf('You have %.2f Liters', conversion)
    end
    if data1 == 2 && data2 == 4
        conversion = numeric * 7.481;
        fprintf('You have %.2f US Gallons', conversion)
    end
    if data1 == 3 && data2 == 1
        conversion = numeric / 1000;
        fprintf('You have %.2f Cubic Meters', conversion)
    end
    if data1 == 3 && data2 == 2
        conversion = numeric / 28.317;
        fprintf('You have %.2f Cubic Feet', conversion)
    end
    if data1 == 3 && data2 == 4
        conversion = numeric / 3.785;
        fprintf('You have %.2f US Gallon', conversion)
    end
    if data1 == 4 && data2 == 1
        conversion = numeric / 264.172;
        fprintf('You have %.2f Cubic Meters', conversion)
    end
    if data1 == 4 && data2 == 2
        conversion = numeric / 7.481;
        fprintf('You have %.2f Cubic Feet', conversion)
    end
    if data1 == 3 && data2 == 3
        conversion = numeric * 3.785
        fprintf('You have %.2f Liters', conversion)
    end
end


