%% If for example
clear 
clc

x = -10:.1:15;

for i = 1:length(x);
    if x(i)<-1;
        y(i) = exp(x(i)+1);
    elseif x(i)>=-1 & x(i)<5;
        y(i) = 4*(x(i)-5);
    else x(i) > 5;
        y(i) = 2+cos(pi*x(i));
    end
end
plot(x,y)
        
    