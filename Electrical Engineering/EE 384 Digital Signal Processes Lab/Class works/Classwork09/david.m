% plotMrmRetLog.m
% This script prompts the user for a MRM-RET logfile, reads, parses, and
% produces a "waterfall plot" of the motion filtered scans and detection lists 
% in the logfile
clear all; close all; clc

%% Query user for logfile
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb,dnmb] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb,fnmb));
[cfgb,reqb,scnb,det] = readMrmRetLog(fullfile(dnmb,fnmb));

[fnmt,dnmt] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt,fnmt));
[cfgt,reqt,scnt,dett] = readMrmRetLog(fullfile(dnmt,fnmt));

[fnmt2,dnmt2] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt2,fnmt2));
[cfgt2,reqt2,scnt2,dett2] = readMrmRetLog(fullfile(dnmt2,fnmt2));

[fnmt3,dnmt3] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt3,fnmt3));
[cfgt3,reqt3,scnt3,dett3] = readMrmRetLog(fullfile(dnmt3,fnmt3));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved)
rawscansIb = find([scnb.Nfilt] == 1);
rawscansV_background = reshape([scnb(rawscansIb).scn],[],length(rawscansIb))';

rawscansIt = find([scnt.Nfilt] == 1);
rawscansIt2 = find([scnt2.Nfilt] == 1);
rawscansIt3 = find([scnt3.Nfilt] == 1);


rawscansV_target = reshape([scnt(rawscansIt).scn],[],length(rawscansIt))';
rawscansV_target2 = reshape([scnt2(rawscansIt2).scn],[],length(rawscansIt2))';
rawscansV_target3 = reshape([scnt3(rawscansIt3).scn],[],length(rawscansIt3))';


scan_difference05 = abs(rawscansV_background - rawscansV_target);
scan_difference10 = abs(rawscansV_background - rawscansV_target2);
scan_difference15 = abs(rawscansV_background - rawscansV_target3);


%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference05(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
%figure(1);
%plot(Rbin,rawscansV_background(10,:))  
%Taget plot
%figure;plot(Rbin,rawscansV_target(10,:))
%Difference plot
figure(1);
hold on;
plot(Rbin,scan_difference05(10,:));
plot(Rbin,scan_difference10(10,:));
plot(Rbin,scan_difference15(10,:));
legend('0.5m', '1.0m', '1.5m');
title('Target distances vs background');

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%distance=Rbin(i+99);                        %100=0.9m, 122=1.1m
[a05,i]=max(scan_difference05(10,:)); 
distance=Rbin(i);
[a10,i2]=max(scan_difference10(10,:)); 
distance2=Rbin(i2);
[a15,i3]=max(scan_difference15(10,:)); 
distance3=Rbin(i3);

figure(2);
hold on
pow05 = a05^2;
pow10 = a10^2;
pow15 = a15^2;
scatter(i,pow05, 'filled');
scatter(i2,pow10, 'filled');
scatter(i3,pow15, 'filled');
legend('0.5m', '1.0m', '1.5m');
title('Target distance signal power');

scan_difference05_avg = zeros(1,length(scan_difference05(1,:))); 
scan_difference10_avg = zeros(1,length(scan_difference10(1,:))); 
scan_difference15_avg = zeros(1,length(scan_difference15(1,:))); 


for i=1:10
    scan_difference05_avg = scan_difference05_avg+scan_difference05(i,:); 
    scan_difference10_avg = scan_difference10_avg+scan_difference10(i,:);
    scan_difference15_avg = scan_difference15_avg+scan_difference15(i,:);
end

scan_difference05_avg = scan_difference05_avg/10;
scan_difference10_avg = scan_difference10_avg/10;
scan_difference15_avg = scan_difference15_avg/10;


[c05,i] = max(scan_difference05_avg);
[c10,j] = max(scan_difference10_avg);
[c15,k] = max(scan_difference15_avg);

figure(3);
hold on;
plot(Rbin, scan_difference05_avg);
plot(Rbin,scan_difference10_avg);
plot(Rbin, scan_difference15_avg);
legend('0.5m', '1.0m', '1.5m');
title('Average signal amplitidue');

figure(4);
hold on;
powavg05 = c05^2;
powavg10 = c10^2;
powavg15 = c15^2;
scatter(i,powavg05, 'filled');
scatter(j,powavg10, 'filled');
scatter(k,powavg15, 'filled');

scatter(i,pow05, '*');
scatter(i2,pow10, '*');
scatter(i3,pow15, '*');

legend('0.5m', '1.0m', '1.5m');
title('Average signal power vs raw signal power');


% distance05=Rbin(i)
% distance10=Rbin(i2)
% distance15=Rbin(i3)
