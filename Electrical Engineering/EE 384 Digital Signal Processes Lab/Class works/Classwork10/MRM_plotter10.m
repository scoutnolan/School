% plotMrmRetLog.m
% This script prompts the user for a MRM-RET logfile, reads, parses, and
% produces a "waterfall plot" of the motion filtered scans and detection lists 
% in the logfile
clear all; close all; clc

%% Query user for logfile
%dnm = '.'; fnm = 'MRM_002.csv';
for count = 6:15
    [fnmb,dnmb] = uigetfile('*.csv');
    fprintf('Reading logfile %s\n',fullfile(dnmb,fnmb));
    [cfgb,reqb,scnb,det] = readMrmRetLog(fullfile(dnmb,fnmb));

    [fnmt,dnmt] = uigetfile('*.csv');
    fprintf('Reading logfile %s\n',fullfile(dnmt,fnmt));
    [cfgt,reqt,scnt,dett] = readMrmRetLog(fullfile(dnmt,fnmt));

    %% Pull out the raw scans (if saved)
    rawscansIb = find([scnb.Nfilt] == 1);
    rawback = reshape([scnb(rawscansIb).scn],[],length(rawscansIb))';

    rawscansIt = find([scnt.Nfilt] == 1);
    rawtar = reshape([scnt(rawscansIt).scn],[],length(rawscansIt))';

    if count == 6
        sdiff6 = abs(rawback - rawtar);
        s6 = sdiff6;
    elseif count == 7
        sdiff6 = abs(rawback - rawtar);
        s7 = sdiff6;
    elseif count == 8
        sdiff6 = abs(rawback - rawtar);
        s8 = sdiff6;
    elseif count == 9
        sdiff6 = abs(rawback - rawtar);
        s9 = sdiff6;
    elseif count == 10
        sdiff6 = abs(rawback - rawtar);
        s10 = sdiff6;
    elseif count == 11
        sdiff6 = abs(rawback - rawtar);
        s11 = sdiff6;
    elseif count == 12
        sdiff6 = abs(rawback - rawtar);
        s12 = sdiff6;
    elseif count == 13
        sdiff6 = abs(rawback - rawtar);
        s13 = sdiff6;
    elseif count == 14
        sdiff6 = abs(rawback - rawtar);
        s14 = sdiff6;
    elseif count == 15
        sdiff6 = abs(rawback - rawtar);
        s15 = sdiff6;
    end

    %% Create the waterfall horizontal and vertical axes
    Tbin = 32/(512*1.024);  % ns
    T0 = 0; % ns
    c = 0.29979;  % m/ns
    Rbin = c*(Tbin*(0:size(sdiff6(1,:),2)-1) - T0)/2;% Range Bins in meters

    % Difference plot
    % plot(Rbin,sdiff6(10,:))
    [a6,i]=max(sdiff6(10,:));
    if count == 6
        sample = sdiff6(10,23:67);
        var = var(sample);
        SNR6 = 10*log10(a6^2/var);
    elseif count == 7
        sample = sdiff6(10,23:67);
        var = var(sample);
        SNR7 = 10*log10(a6^2/var);
    elseif count == 8
        sample = sdiff6(10,23:67);
        var = var(sample);
        SNR8 = 10*log10(a6^2/var);
    elseif count == 9
        sample = sdiff6(10,23:67);
        var = var(sample);
        SNR9 = 10*log10(a6^2/var);
    elseif count == 10
        sample = sdiff6(10,23:67);
        var = var(sample);
        SNR10 = 10*log10(a6^2/var);
    elseif count == 11
        sample = sdiff6(10,23:67);
        var = var(sample);
        SNR11 = 10*log10(a6^2/var);
    elseif count == 12
        sample = sdiff6(10,23:67);
        var = var(sample);
        SNR12 = 10*log10(a6^2/var);
    elseif count == 13
        sample = sdiff6(10,23:67);
        var = var(sample);
        SNR13 = 10*log10(a6^2/var);
    elseif count == 14
        sample = sdiff6(10,23:67);
        var = var(sample);
        SNR14 = 10*log10(a6^2/var);
    elseif count == 15
        sample = sdiff6(10,23:67);
        var = var(sample);
        SNR15 = 10*log10(a6^2/var);
    end
end
figure(1);
hold on;
xlabel("Distance (m)");
ylabel("Amplitude");
plot(Rbin, s6), plot(Rbin, s7), plot(Rbin, s8), plot(Rbin, s9), plot(Rbin, s10)
plot(Rbin, s11), plot(Rbin, s12), plot(Rbin, s13), plot(Rbin, s14), plot(Rbin, s15)
legend('PII6', 'PII7', 'PII8', 'PII9', 'PII10', 'PII11', 'PII12', 'PII13', 'PII14', 'PII15');
hold off;
PII = (6:15);
SNR = [SNR6 SNR7 SNR8 SNR9 SNR10 SNR11 SNR12 SNR13 SNR14 SNR15];
figure(2);
plot(PII, SNR);
xlabel('PII 6-15');
ylabel('SNR');
