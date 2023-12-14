%% Lab 11
% plotMrmRetLog.m
% This script prompts the user for a MRM-RET logfile of background and target
% reads, parses, and detection lists in the logfile 
clear all; close all; clc

%% Query user for logfile
[fnmb,dnmb] = uigetfile('*.csv'); 
fprintf('Reading logfile1 %s\n',fullfile(dnmb,fnmb)); 
[cfgb,reqb,scnb,detb] = readMrmRetLog(fullfile(dnmb,fnmb)); 

[fnmt,dnmt] = uigetfile('*.csv'); 
fprintf('Reading logfile2 %s\n',fullfile(dnmt,fnmt)); 
[cfgt,reqt,scnt,dett] = readMrmRetLog(fullfile(dnmt,fnmt)); 

%% Pull out the raw scans
rawscansI = find([scnb.Nfilt] == 1); 
rawscansV_background = reshape([scnb(rawscansI).scn],[],length(rawscansI))'; 
rawscansI1 = find([scnt.Nfilt] == 1); 
rawscansV_target = reshape([scnt(rawscansI1).scn],[],length(rawscansI1))'; 
scan_difference = abs(rawscansV_background-rawscansV_target); 

%% Create the horizontal and vertical axes
Tbin = 32/(512*1.024); % ns 
T0 = 0;      % ns
c = 0.29979; % m/ns 
Rbin = c*(Tbin*(0:size(scan_difference(1,:),2)-1) - T0)/2; % Range Bins in meters 

figure; plot(Rbin,scan_difference); title('scan difference'); xlabel('Rbin'); ylabel('amplitude'); 
figure; plot(Rbin,scan_difference(10,:)); title('scan difference (10)'); xlabel('Rbin'); ylabel('amplitude'); 

%% 6. Plot the spectrum of the signal
x = scan_difference(10,:);  % Sample Data
L = length(x);              % Window length
n = pow2(nextpow2(L));      % Next power of 2 from length of y
y_dft= fft(x,n);            % DFT
y_s = fftshift(y_dft);      % Rearrange y values
Ts = Tbin*1e-9;             % Tbin is given in nsec
fs = 1/Ts;
f = (-n/2:n/2-1)*(fs/n);    % 0-centered frequency range
fnz = (0:n-1)*(fs/n);       % Nonzero-centered frequency range
figure; plot(fnz,abs(y_dft)/n); title('6c(i)'); xlabel('fnz'); ylabel('amplitude'); 
figure; plot(f,abs(y_s)/n); title('6c(iii)'); xlabel('f'); ylabel('amplitude'); 

%% Butterworth Low Pass Filter Design
fpass = 4.9e9; fstop = 5.6e9; 
Wp = (2*fpass)/fs; 
Ws = (2*fstop)/fs; 
Rp = 1; 
Rs = 20; 
[n,Wn] = buttord(Wp,Ws,Rp,Rs); 
[b,a] = butter(n,Wn,'low'); 
yf = filter(b,a,x); 

temp = yf;  % Sample Data
L = length(temp);           % Window length
n = pow2(nextpow2(L));      % Next power of 2 from length of y
y_dft= fft(temp,n);         % DFT
y_s = fftshift(y_dft);      % Rearrange y values
Ts = Tbin*1e-9;             % Tbin is given in nsec
fs = 1/Ts; 
f = (-n/2:n/2-1)*(fs/n); 	% 0-centered frequency range
figure; plot(f,abs(y_s)/n); title('Butterworth Low Pass Filter Design'); xlabel('f'); ylabel('amplitude'); 
figure; plot(Rbin,yf,Rbin,x); title('Butterworth Low Pass Filter'); xlabel('Rbin'); ylabel('amplitude'); legend('Filtered Signal','Original Sample data'); 

%% Butterworth High Pass Filter Design
fpass = .1e9; fstop = .05e9; 
Wp = (2*fpass)/fs; 
Ws = (2*fstop)/fs; 
Rp = 1; 
Rs = 20; 
[n,Wn] = buttord(Wp,Ws,Rp,Rs); 
[b,a] = butter(n,Wn,'high'); 
yfh = filter(b,a,yf); 

temp = yfh;  % Sample Data
L = length(temp);           % Window length
n = pow2(nextpow2(L));      % Next power of 2 from length of y
y_dft= fft(temp,n);         % DFT
y_s = fftshift(y_dft);      % Rearrange y values
Ts = Tbin*1e-9;             % Tbin is given in nsec
fs = 1/Ts; 
f = (-n/2:n/2-1)*(fs/n); 	% 0-centered frequency range
figure; plot(f,abs(y_s)/n); title('Butterworth High Pass Filter Design'); xlabel('f'); ylabel('amplitude'); 
figure; plot(Rbin,yfh,Rbin,x,Rbin,yf); title('Butterworth High Pass Filter'); xlabel('Rbin'); ylabel('amplitude'); legend('High Pass Filtered','Original Sample data','Low Pass Filtered Signal'); 

%% Chebyshev Type I Low Pass
Wp = (2*fpass)/fs; 
Ws = (2*fstop)/fs; 
Rp = 1; 
Rs = 20; 
[n,Wn] = cheb1ord(Wp,Ws,Rp,Rs); 
[b,a] = cheby1(n,Rp,Wp,'low'); 
yf = filter(b,a,x); 

temp = yf;  % Sample Data
L = length(temp);           % Window length
n = pow2(nextpow2(L));      % Next power of 2 from length of y
y_dft= fft(temp,n);         % DFT
y_s = fftshift(y_dft);      % Rearrange y values
Ts = Tbin*1e-9;             % Tbin is given in nsec
fs = 1/Ts; 
f = (-n/2:n/2-1)*(fs/n);    % 0-centered frequency range
figure; plot(f,abs(y_s)/n); title('Chebyshev Type I Low Pass Filter Design'); xlabel('f'); ylabel('amplitude'); 
figure; plot(Rbin,yf,Rbin,x); title('Chebychev Type I Low Pass Filter'); xlabel('Rbin'); ylabel('amplitude'); legend('Filtered Signal','Original Sample data'); 

%% Chebyshev Type I High Pass
Wp = (2*fpass)/fs; 
Ws = (2*fstop)/fs; 
Rp = 1; 
Rs = 20; 
[n,Wn] = cheb1ord(Wp,Ws,Rp,Rs); 
[b,a] = cheby1(n,Rp,Wp,'high'); 
yfh = filter(b,a,yf); 

temp = yfh;  % Sample Data
L = length(temp);           % Window length
n = pow2(nextpow2(L));      % Next power of 2 from length of y
y_dft= fft(temp,n);         % DFT
y_s = fftshift(y_dft);      % Rearrange y values
Ts = Tbin*1e-9;             % Tbin is given in nsec
fs = 1/Ts; 
f = (-n/2:n/2-1)*(fs/n); 	% 0-centered frequency range
figure; plot(f,abs(y_s)/n); title('Chebyshev Type I High Pass Filter Design'); xlabel('f'); ylabel('amplitude'); 
figure; plot(Rbin,yfh,Rbin,x,Rbin,yf); title('Chebychev Type I High Pass Filter'); xlabel('Rbin'); ylabel('amplitude'); legend('Filtered Signal','Original Sample data','Low Pass Filtered Signal')
