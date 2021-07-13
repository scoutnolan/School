f = 1;
t = 0:0.1:5;
x = (exp(-t).*sin(2*f.*t))/2;

R = 2;
C = 1;
b = exp(-t/(R*C))
y = (2-exp(b));

plot(t, y), title('e^-t * 1/2 * sin(2t)'), xlabel('time')