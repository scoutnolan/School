% Homework one Problem one
% Nolan Anderson
% Eng 101
% 2/4/2019





ta = input('What is the current air temperature?  ');
v = input('What is the current wind speed in miles per hour?   ');

vx = v*(exp(.16));

%twc = 35.74 + 0.6215*(ta) - 35.75*(v)*(exp(0.16)) + 0.4275*(ta)*((v)*(exp(0.16)));
twc = 35.74 + 0.6215*ta-35.75*(v^.16)+0.4275*ta*(v^.16)
difftemp = ta-twc;


fprintf('\n')
fprintf('The wind chill is %f degrees Fahrenheit\n', twc);
fprintf('\n')
fprintf('It feels %f colder than the actual air temperature\n', difftemp);
fprintf('\n')
q1 = input('Is it cold outside for you? [Yes/No]  ', 's');
fprintf('\n')
if q1 == 'Yes'
    disp('Well, dress warmly')
else
    disp('Dress for good temperatures')
end
