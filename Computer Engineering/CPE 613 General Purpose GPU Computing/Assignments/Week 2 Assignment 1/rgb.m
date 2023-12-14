% Image to text
rgb = imread('goats.jpeg');
writematrix(rgb,'goats.txt', 'delimiter', ' ');

% Text to image
filename = 'grayscale.txt'
grayImage = uint8(importdata(filename));
imwrite(grayImage, 'myimage.png');