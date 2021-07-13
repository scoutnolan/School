% for t=1:1:20
%     x=exp(-5*t)
% end

t = 1:1:20;
for i=1:length(t)
    x(i) = exp(-5*t(i))
end

plot(t,x)



