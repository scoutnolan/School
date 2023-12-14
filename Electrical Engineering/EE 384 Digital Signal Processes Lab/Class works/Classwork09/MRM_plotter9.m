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
[cfgt05,reqt05,scnt05,dett05] = readMrmRetLog(fullfile(dnmt,fnmt));

[fnmt,dnmt] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt,fnmt));
[cfgt1,reqt1,scnt1,dett1] = readMrmRetLog(fullfile(dnmt,fnmt));

[fnmt,dnmt] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt,fnmt));
[cfgt15,reqt15,scnt15,dett15] = readMrmRetLog(fullfile(dnmt,fnmt));

%% Pull out the raw scans (if saved)

[diff05, back05, tar05] = readscan(scnb, scnt05);
[diff1, back1, tar1] = readscan(scnb, scnt1);
[diff15, back15, tar15] = readscan(scnb, scnt15);

%% Plot difference, background, target.
[Rbin05, distance05, pow05, i1, a05] = RbinPlot(diff05, back05, tar05, '0.5 Meters');
[Rbin1, distance1, pow1, i2, a1] = RbinPlot(diff1, back1, tar1, '1 Meter');
[Rbin15, distance15, pow15, i3, a15] = RbinPlot(diff15, back15, tar15, '1.5 Meters');

figure
hold on;
plot(Rbin05,diff05(10,:));
plot(Rbin1,diff1(10,:));
plot(Rbin15,diff15(10,:));
legend('0.5m', '1.0m', '1.5m');
title('Target distances vs background');

figure
hold on;
scatter(i1,pow05, 'filled');
scatter(i2,pow1, 'filled');
scatter(i3,pow15, 'filled');
legend('0.5m', '1.0m', '1.5m');
title('Target distance signal power');

%% Create the waterfall horizontal and vertical axes
[avg05, new_distance05, max05, i] = difference(diff05, Rbin05);
[avg1, new_distance1, max1, j] = difference(diff1, Rbin1);
[avg15, new_distance15, max15, k] = difference(diff15, Rbin15);

%% Create the amplitude plot.
figure;
hold on;
plot(Rbin05, avg05);
plot(Rbin1, avg1);
plot(Rbin15, avg15);
legend('0.5m', '1.0m', '1.5m');
title('Average signal amplitidue');

%% Get the power of each Measurement. 
figure;
hold on;
powavg05 = max05^2;
powavg10 = max1^2;
powavg15 = max15^2;
scatter(i,powavg05, 'filled');
scatter(j,powavg10, 'filled');
scatter(k,powavg15, 'filled');
scatter(i1,pow05, '*');
scatter(i2,pow1, '*');
scatter(i3,pow15, '*');

legend('0.5m', '1.0m', '1.5m');
title('Average signal power vs raw signal power');

%% Functions
function[diff, back, tar] = readscan(scnb, scnt)
    rawscansIb = find([scnb.Nfilt] == 1);
    back = reshape([scnb(rawscansIb).scn],[],length(rawscansIb))';

    rawscansIt = find([scnt.Nfilt] == 1);
    tar = reshape([scnt(rawscansIt).scn],[],length(rawscansIt))';

    diff = abs(back - tar);
end

function[Rbin, distance, pow, i, a05] = RbinPlot(diff, back, tar, name)
    Tbin = 32/(512*1.024);  % ns
    T0 = 0; % ns
    c = 0.29979;  % m/ns
    Rbin = c*(Tbin*(0:size(diff(1,:),2)-1) - T0)/2;
    target = append('Target', ' ', name);
    difference = append('Difference',' ', name);
    %Background plot
    figure
    subplot(3,1,1);
    plot(Rbin,back(10,:)), xlabel('Distance'), ylabel('Amplitude'), title('Background')  
    %Taget plot
    subplot(3,1,2);
    plot(Rbin,tar(10,:)), xlabel('Distance'), ylabel('Amplitude'), title(target)  
    % Difference plot
    subplot(3,1,3);
    plot(Rbin,diff(10,:)), xlabel('Distance'), ylabel('Amplitude'), title(difference)  

    [a05,i]=max(diff(10,:)); 
    distance = Rbin(i);

    pow =a05^2;
end

function[avg, distance, c, i] = difference(diff, Rbin)
    avg = zeros(1,length(diff(1,:))); 
    for i=1:10 
        avg = avg + diff(i,:); 
    end
    avg = avg / 10; 
    [c, i] = max(avg); 
    distance = Rbin(i);
end
