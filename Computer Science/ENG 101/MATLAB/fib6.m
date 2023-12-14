a=1;
b=1;
c=a+b;
element = 3; % Instead of starting at 1, start at 0 because c=a+b is the 3rd step
while(c<100000) %This while loop will continue until it sees 6 digits, first 6 digit number is 100000
    a=b; % assigns a to b as they get added together
    b=c; %assigns b to c as they get added together
    c=a+b; %adding the previous two numbers together after assigning them to each other
    element = element + 1; %keeps up with which element in the list
end
fprintf('%.0f is the first 6 digit number in the fibonacci sequence, and it is number %.0f in the list.\n', c, element)
    
