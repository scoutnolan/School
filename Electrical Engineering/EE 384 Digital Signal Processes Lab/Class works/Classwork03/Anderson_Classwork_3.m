%% Nolan Anderson
% EE 384 
% Classwork 2
% Due 5 September 2021

%% Problem 1

% a
x = [1 2 3 4 5 6 7 8];
X = fft(x)

% b
Y = ifft(X)

% c
N = length(x);
z = zeros(1, N);
Sum = 0;
for k = 1 : N
    for L = 1 : N
         Sum = Sum + x(L) * exp(-2*1i*pi*(L-1)*(k-1)/N);
    end
    z(k) = Sum;
    Sum = 0;
end

for k = 1 : N
    for L = 1 : N
         Sum = Sum + z(L) * exp(2*1i*pi*(L-1)*(k-1)/N);
    end
    x(k) = (1/N) * Sum;
    Sum = 0;
end
z
x
%% Problem 2

% a
f1 = 697; f2 = 1209; fs = 8000; % 697 Hz / 1209 Hz / 8 kHz
dt = 1/fs;
t = 0 : dt : 1-dt;
y = sin(2*pi*f1*t) + sin(2*pi*f2*t);
plot(t, y), xlabel('t'), ylabel('y(t)'), title('Problem 2a');

% b 
figure
y_psd = periodogram(y);
plot(10*log10(y_psd))
title('Frequence spectrum using Matlab function periodogram')
xlabel('Frequency (Hz)'), ylabel('dB')
text(697, 10*log10(y_psd(697)), ' 697 Hz \rightarrow', 'HorizontalAlignment','right');
text(1209, 10*log10(y_psd(1209)), ' 697 Hz \rightarrow', 'HorizontalAlignment','right');

% c
% see screenshot below.

% d
L = length(y);
n = pow2(nextpow2(L));
y_dft = fft(y, n);
y_s = fftshift(y_dft);
f = (-n/2 : n/2 - 1) * (fs / n);

figure
plot(f, abs(y_s) / n);