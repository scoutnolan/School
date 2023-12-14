minDistance = inf;
minT = 0;
for t = linspace(1,5,20)
    x = 5.*(t)-10;
    y = 25.*t.^2-120.*t+144;
    distance = sqrt(x^2 + y^2);
    if distance < minDistance
        minDistance = distance;
        minT = t;
    end
end
fprintf('The minimum distance of %.2f occurs at t = %.3f\n', minDistance, minT);

    