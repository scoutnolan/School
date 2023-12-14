%% random number guessing

t = input('Please enter a number bewteen 1 and 100   ');
x = randi([1,100])
i = 0;
while t ~= x
    i = i + 1;
    if i < 3
        while t < x
            t = input(sprintf('The number is too low. Please try again. You have %d more tries  \n', i));
        end
        while t > x
            t = input(sprintf('The number is too high, try again. You have %d more tries  \n', i));
        end
        
        if i > 3
            t = disp('You have tried to guess too may times');
            break
        end
    end
end

if t == x
    fprintf('Good job! The number was %g ', x);
end
