% %Creating and adding to an array
% %Enter input queries
clear 
clc
% 
% n1 = input('Enter a starting number (positive integer):   ');
% n2 = input('Enter an ending number (positive and greater than n1):    ');
% 
% %create an empty array
% range[];
% for i = n1 : n2
%     range = [n1 n2];
%     n1 = n1 + 1;
% end
% 
% disp(range)


%% Stars
% rows = input('How many rows of stars do you want   ');
% for r = 1:rows
%     for s = 1 : r
%         fprintf('*');
%     end
%     fprintf('\n')
% end

%% Running sum
% x = [1 8 3 9 0 1];
% total = 0;
% array_total=[];
% for j = 1:length(x);
%     total = total + x(j);
%     array_total = [array_total total];
% end
% disp(total)
% disp(array_total)
%


%% random numbers

% x = 0;
% count = 0;
% 
% while ((x >= 12) | (x <= 2)) 
%     x = randi([1,100]);
%     count = count + 1;
% 
% end
% 
% disp(x)
% disp(count)


%% random number guessing

t = input('Please enter a number bewteen 1 and 100   ');
x = randi([1,100]);

while t ~= x
    while t < x
        t = input('The number is too low. Please try again.  ');
    end
    while t > x
        t = input('The number is too high, try again.  ');
    end
    if t == x
        fprintf('Good job! The number was %g ', x);
    end
end




    



 





