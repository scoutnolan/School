clear 
clc
%Basketball stats
p_name = 'Sam';
games = 100;
totalgames = 130
gamespercent = (games/totalgames)*100
ppg = 14.1738;
reb = 10.9;
assists = 4.359;

fprintf('\tOver %g games, %s scored and average of %5.17f points per game.\n' , games, p_name, ppg)
fprintf('\tOver %.0f games, %s scored an average of %g rebounds per game.\n' , games, p_name, reb)
fprintf('\t%s played in %g%% of total games.\n', p_name, gamespercent)