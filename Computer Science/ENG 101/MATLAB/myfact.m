function [output] = myfact(mynumber)
% This function finds the factorial of any number
if mynumber > 0
    while mynumber > 1
        output = mynumber * mynumber-1;
        fprintf('The factorial of %.1f is %d ', mynumber, output)
    end
end
if mynumber < 0
    disp('This is not possible')
end




end

