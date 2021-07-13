function [ perfect ] = isperfect( n )
% This function checks to see if the given number is "perfect";
%   a "perfect" number is an integer whose factors (excluding 
%   itself) add up to it.
%
%   Example:  6    is a perfect number:   1 + 2 + 3 = 6  == 6
%             8    is not                 1 + 2 + 4 = 7  ~= 8
%
% Arguments:
%
%       test_value        (input)     check to see if this value is
%                                     perfect or not
%
%       perfect           (output)    if yes, set this to 1
%                                     if no, set this to 0
%
% 

    sum=1;
    for i=2:floor(sqrt(n))
        if(mod(n,i)==0)
            sum=sum+i+n/i;
        end
    end
    if(sum==n && n~=1)
        perfect=true;
    else
        perfect=false;
    end
end

