%% Homework 2 Number Guessing Game 
% Nolan Anderson
% ENG 101
% 2/20


% random number guessing

t = input('Please enter a number bewteen 1 and 100   ');
x = randi([1,100]);
i = 0;
while (1)
    m = input('Do you want to continue? Y/N ','s');
    if m == 'N'
        break;
    end
    while  t ~= x
            i = i+1;
            if i < 3 && t < x
               
                t = input(sprintf('The number is too low. Please try again. You have %d more tries  \n', i));
                m = input('Do you want to continue? Y/N ','s');
                if m == 'N'
                    break;
                end
            end
            i = i+1;
            if i < 3 && t > x
                
                t = input(sprintf('The number is too high, try again. You have %d more tries  \n', i));
                m = input('Do you want to continue? Y/N ','s');
                if m == 'N'
                    break;
                end
            end
            
            
            
            if i >= 3
                fprintf('You have tried to guess too may times, the number was %.0f\n',x);
                return;
            end
    end
end

if t == x
    fprintf('Good job! The number was %g \n', x);
end


