filename = 'Anderson_N_orig.wav';
F1 = 2200; F2 = 2210;           % Left and right audio
info = audioinfo(filename);     % Info of the audio file
[y, Fs] = audioread(filename);  % Read the audio into y and Fs
Ts = 1/Fs;                      % Ts
t = 0:Ts:info.Duration;     
tnew = 10:Ts:info.Duration;
t3 = 0:Ts:10;
A = max(0.1*max(y));            % Maximum amplitude

x = A.*sin((2*pi*F1*tnew) + pi/3);
z = A.*sin((2*pi*F2*tnew) + 0);

index = length(t3);
for n = 1:length(x)
    y(index, 1) = x(n);
    y(index, 2) = z(n);
    index = index +1;
end

audiowrite('Anderson_N_matlab.wav', y, Fs);