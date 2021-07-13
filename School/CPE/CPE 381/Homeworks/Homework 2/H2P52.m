syms t x1 x2 s
x1=4*exp(-2*t)*cos(8*t)*heaviside(t);
x2=4*exp(-4*t)*cos(8*t)*heaviside(t);

figure
X1=laplace(x1)
X12 = (4*(s + 2))/((s + 2)^2 + 64);
subplot(221)
fplot(x1, [0,5]),title('4*exp(-2*t)*cos(8*t)*u(t)'),xlabel('time[s]')


X2=laplace(x2)
X13 = (4*(s + 4))/((s + 4)^2 + 64);
subplot(222)
fplot(x2, [0,5]),title('4*exp(-4*t)*cos(8*t)*u(t)'),xlabel('time[s]')

subplot(223)
splane([4 8],[1 4 68])
subplot(224)
splane([4 16],[1 8 80])

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