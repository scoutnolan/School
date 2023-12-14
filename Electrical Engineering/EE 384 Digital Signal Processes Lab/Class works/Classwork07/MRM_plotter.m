% plotMrmRetLog.m
% This script prompts the user for a MRM-RET logfile, reads, parses, and
% produces a "waterfall plot" of the motion filtered scans and detection lists 
% in the logfile
clear all; close all; clc

%% Query user for logfile
%dnm = '.'; fnm = 'MRM_002.csv';
[fnm,dnm] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnm,fnm));
[cfg,req,scn,det] = readMrmRetLog(fullfile(dnm,fnm));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved)
rawscansI = find([scn.Nfilt] == 1);
rawscansV = reshape([scn(rawscansI).scn],[],length(rawscansI))';
% band-pass filtered scans
bpfscansI = find([scn.Nfilt] == 2);
bpfscansV = reshape([scn(bpfscansI).scn],[],length(bpfscansI))';
% motion filtered scans
mfscansI = find([scn.Nfilt] == 4);
mfscansV = reshape([scn(mfscansI).scn],[],length(mfscansI))';


%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(rawscansV,2)-1) - T0)/2;  % Range Bins in meters

figure
plot(Rbin, rawscansV), title('Raw scan'), xlabel('Time'), ylabel('Frequency');
figure
plot(Rbin, bpfscansV), title('Band Filter scan'), xlabel('Time'), ylabel('Frequency');
figure
plot(Rbin, mfscansV), title('Match Filter scan'), xlabel('Time'), ylabel('Frequency');
figure 
hold on
plot(Rbin, rawscansV);
plot(Rbin, bpfscansV);
plot(Rbin, mfscansV);
title('Filters overlayed');
legend('Raw', 'Match Filter', 'Band Filter');