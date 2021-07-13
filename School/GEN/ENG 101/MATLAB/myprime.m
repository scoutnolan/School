function [x] = myprime(n)


if rem(n,n) == 1 && n/1 == n
    x = 1
if rem(n,n) ~= 1 
    x = 0
end

end

