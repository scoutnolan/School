%% Nolan Anderson
% CPE 381 Homework 5 # 1
%% Variables
i = [1 0 -0.2];          
j = 1; 
x = [1 zeros(1,30)];
h = filter(j,i,x);
n = 0:30;
%% Plot
stem(n,h); axis([0 30 0 1]);
grid;
ylabel('h[n]'); 
xlabel('n')


