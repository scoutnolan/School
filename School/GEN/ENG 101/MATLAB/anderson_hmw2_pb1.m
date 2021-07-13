% % Homework 2 Number Guessing Game 
% Nolan Anderson
% ENG 101
% 2/20


%% Initial data
x = randi([1,100]);
i = 0;
t = input('Please enter a number bewteen 1 and 100   ');
i = i + 1;

%% Output Based on Input and Attempts
while(1) 
    if t ~= x && i == 1 % If i is equal to 1, and t doesnt match x, run these if statements.
        
        if i < 3 && t < x % if the number is less than x, and i equal to 1, tell the user their number is too low and give them their amount of attempts.
            t = input(sprintf('The number is too low, try again. You have %d more tries  \n', i+1));
            i = i + 1; % adds and attempt to i
        end
        
        if i < 3 && t > x % if the number is greater than x, and i equal to 2, tell the user their number is too high and give them their amount of attempts.
            t = input(sprintf('The number is too high, try again. You have %d more tries  \n', i+1));
            i = i + 1   ;   % adds an attempt to i   
        end
        
        
        m = input('Would you like to continue? y/n ', 's'); % my attempt to allow the user to exit the program. Essentially breaks the code if the user types in 'n'
        if m == 'n' || m == 'N'
            break;
        end
    end
    
    
    
    if t ~= x && i == 2 % while i is equal to 2, and t doesnt match x, run these if statements.
        
        if i == 2 && t < x % if the number is less than x, and i equal to 2, tell the user their number is too low and give them their amount of attempts.
            t = input(sprintf('The number is too low, try again. You have %d more tries  \n', i-1));
            i = i + 1  ;% adds an attempt to i    
        end
        
        if i == 2 && t > x % if the number is greater than x, and i equal to 2, tell the user their number is too high and give them their amount of attempts.
            t = input(sprintf('The number is too high, try again. You have %d more tries  \n', i-1));
            i = i + 1  ; % adds an attempt to i
        end
        
        
        m = input('Would you like to continue? y/n ', 's'); % my attempt to allow the user to exit the program. Essentially breaks the code if the user types in 'n'
        if m == 'n' || m == 'N'
            break;
        end
        
    end
    
    
%% Output if the user "won" or tried too many times.
    if i == 3 % if i, the amount of times the user has inputted a guess, equals 3, stop the code.
        fprintf('You have tried to guess too may times, the number was %.0f\n',x);
        return;
    end
    if t == x % if the guess equals the random number, ends the code with a comment.
        fprintf('Good job! The number was %g \n', x);
        return;
    end
end





