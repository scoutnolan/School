A = 0;
B = 1;
fib=[A B];
for i = 3:100
    
    C = A + B;
% move everything over one spot
    A = B; % eliminate old A
    B = C;
    fib=[fib C];
end


