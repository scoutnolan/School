%% Day 2 assignment Line Equations


% Variables
m1=-5;
m2=7;
m3=2;


b1=3;  %b is for y - intercept
b2=-6;
b3=12;

x1 = 0:1:20;
x2 = linspace(-5,18,41); %use linspace to give amount of numbers in between numbers
x3 = 4:3:125;

%making the lines
y1 = m1*x1+b1;
y2 = m2*x2+b2;
y3 = m3*x3+b3;

mean_y1 = mean(y1);
mean_y2 = mean(y2);
mean_y3 = mean(y3);

fprintf('Mean y1: %f.2 mean y2: %f.2 mean y3: %f.2', mean_y1, mean_y2, mean_y3)

max_y1 = max(y1);
max_y2 = max(y2);
max_y3 = max(y3);

min_y1 = min(y1);
min_y2 = min(y2);
min_y3 = min(y3);

plot(x1,y1,x2,y2,x3,y3)


