a = 2;
b = 1000;
vector = [];
for n = (a:b)
    if isperfect(n)
        vector(n) = n;
        vector = vector ~= 0;
        fprintf('%d', vector);
    end
    
end

    