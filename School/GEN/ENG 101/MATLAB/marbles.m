r = 20;
b = 4*r-10;
y = (2*b)/(0.7*r);
g = y + ((r + b)/10);

count = r + b + y + g;

fprintf('You have %.0f red marbles\n', r)
fprintf('You have %0.f blue marbles\n',b)
fprintf('You have %0.f yellow marbles\n',y)
fprintf('You have %0.f green marbles\n',g)
fprintf('You have %g total marbles, %g red marbles, %g blue marbles, %g yellow marbles, %g green marbles.\n', count, r,b,y,g)