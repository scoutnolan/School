t = 0:0.0001:4;
for i = 1:length(t)
    x(i) = 5*t(i)-10;
    y(i) = 25*t(i)^2-120*t(i)+144;
    d(i) = sqrt(x(i)^2+y(i)^2);
end
mindis = min(d);
i = find(d==mindis);
time = (i-1)*0.0001

    