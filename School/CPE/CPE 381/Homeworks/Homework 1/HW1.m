%% Initial Declaration
Fs = 20;        % Sampling Frequency, 20hz.
Ts = 1/Fs;      % Sampling interval.
f = 2;          % 2 Hz
t = 0:Ts:4;     % Time 
t2 = -4:Ts:0;   % t <= 0 time
A = 2;          % Amplitude
t3 = 0:Ts:6;
t4 = -2:Ts:0;
ee3 = exp(-t3);
%% Number 4
env = A*ee;                     % Envelope
env2 = -A*ee;                   % Envelope
ee = exp(-t);
y = A*ee.*sin(2*pi*f*t);        % Function 
y2 = zeros(size(t2));           % t < = 0
figure
plot(t, y,'b', t2, y2, 'b', t, env, 'r:', t, env2, 'r:'), xlabel('t [s]'),ylabel('Amplitude'),grid
%% Number 5
env3 = A*ee3;                   % Envelope
env4 = -A*ee3;                  % Envelope
y3 = A*ee3.*sin(2*pi*f*t3);     % Function with new time
y4 = zeros(size(t4));           % t < = 0
tow = 2-t3;                     % Function shift
tow2 = 2-t4;                    % Function shift
figure
plot(tow, y3,'b', tow2, y4, 'b', tow, env3, 'r:', tow, env4, 'r:'), xlabel('t [s]'),ylabel('Amplitude'),grid

%%
