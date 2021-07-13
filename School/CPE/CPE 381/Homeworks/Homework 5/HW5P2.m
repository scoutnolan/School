b = 0:5;
a = 1;
x = [1 zeros(1,9)];
h = filter(b,a,x);

x = ones(1,10);
s = filter(b, a, x);

subplot(211);
stem(0:9, h);

subplot(212);
stem(0:9, s);