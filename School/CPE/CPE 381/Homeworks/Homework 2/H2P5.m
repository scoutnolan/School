% syms t x1 x2 s
% x1=4*exp(-2*t)*cos(8*t)*heaviside(t);
% x2=4*exp(-4*t)*cos(8*t)*heaviside(t);
% 
% X1=laplace(x1);
% X12 = 4*(s+2)/(s^2+4*s+68);
% H = X1 * X12;
% h = matlabFunction(ilaplace(H));
% t=1:0.01:5;
% plot(t,h(t)),title('4*exp(-2*t)*cos(8*t)*u(t)'),xlabel('time[s]')
% 
% hold on
% X2=laplace(x2);
% X13 = 4*(s+4)/(s^2+8*s+80);
% H2 = X2 * X13;
% h2 = matlabFunction(ilaplace(H2));
% t2=1:0.01:5;
% plot(t2,h2(t2))
% 
% 
% figure 
% pzmap(h(t), h2(t2))


%CPE381: HW2_5
% syms t x1 x2
% x1=5*exp(-2*t)*cos(8*t)*heaviside(t);
% x2=5*exp(-4*t)*cos(8*t)*heaviside(t);
% X1=laplace(x1)
% % X1 = 5*(s+2)/(s^2+4*s+68)
% % plot
% splane([5 10],[1 4 68])
% X2=laplace(x2)
% % X2 = 5*(s+4)/(s^2+8*s+80)
% figure
% % plot
% splane([5 20],[1 8 80])

syms t
x = exp(-t);
X = laplace(x)


function splane(num,dem)

z = roots(num); p = roots(dem);
A1 = [min(imag(z)) min(imag(p))]; A1 = min(A1) - 1;
B1 = [min(imag(z)) min(imag(p))]; B1 = max(B1) + 1;
N = 20;
D = (abs(A1)+abs(B1))/N;
im = A1:D:B1;
Nq = length(im);
re = zeros(1, Nq);
A = [min(real(z)) min(real(p))]; A = min(A) - 1;
B = [max(real(z)) max(real(p))]; B = max(B) + 1;
stem(real(z), imag(z), 'o:')
hold on
stem(real(p), imag(p), 'x:')
plot(re,im,'k');xlabel('\sigma');ylabel('j\Omega'); grid
axis([A 3 min(im) max(im)])
hold off
end