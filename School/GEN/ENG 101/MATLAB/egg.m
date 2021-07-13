A = 1;
B = 1;
C = A+B;
count = 3; % we?ve just calculated element number 3
while(C<100000)
    % move everything over one spot
    A = B; % eliminate old A
    B = C;
    C = A + B;
    count = count+1;
end
fprintf('The first 6 digit Fibonacci number is %.0f, which is element %.0f \n',C,count)