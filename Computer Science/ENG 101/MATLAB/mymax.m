
function y = my_max(n1, n2, n3, n4, n5)
% finds the maximum of 5 different values inputted


    if (n1 > n2 && n1 > n4 && n1 > n5)
        y = n1;
    elseif(n2 > n3 && n2 > n4 && n2 > n5)
        y = n2;
    elseif(n3 > n4 && n3 > n5)
        y = n3;
    elseif(n4 > n5)
        y = n4;
    else
        y = n5;
    end
    
end