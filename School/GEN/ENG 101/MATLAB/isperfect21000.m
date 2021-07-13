%% Perfect numbers 2-1000 using isperfect

clear;
clc;

a = 2;
b = 1000;
vector = []; % creates an empty vector to put values in to
tic % starts time
for n = a:b
    if isperfect(n)
        vector(n) = n;% puts the numbers in to 
        vector = vector(vector~=0); % Deletes the 0 values from the vector, leaving just non zero numbers
        numofperfect = nnz(vector); % Calculates number of non-zerovalues
        fprintf(['There are %d perfect numbers in between 2 and %d. These numbers are\n'], ceil(numofperfect),b) % displays number of perfect numbers and vector boundaries
        fprintf('%d\n', vector) % prints the real numbers from the vector
    end
end
toc % ends time

    