%CPE381: Exam prep
syms s 
figure
X = (2*s+3)/(s^2 + 2*s + 4);
Y = ilaplace(X);
subplot(2,1,1)
fplot(Y, [0,10])
xlim([0,10])
subplot(2,1,2)
splane([2 3], [1 2 4])
eval(subs(Y, 0.2))
