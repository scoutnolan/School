%% Nolan Anderson
% EE 384 
% Classwork 6
% Due 23 September 2021
clear all; clc; close all;

%% Problem 1:
% Histogram Equalization
figure
im = imread('lowcontrast.jpg');
subplot(2,1,1); imshow(im), title('Original low contrast jpg');
subplot(2,1,2); imhist(im);

L = 256;
figure
FinVal = my_histeq(im, L);
subplot(2,1,1); imshow(FinVal), title('My histeq function');
subplot(2,1,2); imhist(FinVal);


%% Problem 2:
% Edge detection
figure
A = imread('lena.bmp');
B = rgb2gray(A);
subplot(2,2,1), imshow(B), title('Original lena.bmp');

% a - roberts
rob = edge(B, 'roberts');
subplot(2,2,2), imshow(rob), title('Roberts Operator');

% b - prewitt
pre = edge(B, 'prewitt');
subplot(2,2,3), imshow(pre), title('Prewitt Operator');

% c - sobel
sob = edge(B, 'sobel', 'both');
subplot(2,2,4), imshow(sob), title('Sobel Operator');

%% Problem 3:
% Laplacian edge sharpening

%Input Image
A = im2double(imread('oak.jpg'));
mask = [-1 -1 -1; -1 8 -1; -1 -1 -1];

% imfilter for convolution of image and mask
ConvImg = imfilter(A, mask);

% Normalize convolved image
minC = min(ConvImg(:));
maxC = max(ConvImg(:));
ConvImg = (ConvImg - minC) / (maxC - minC);

% Add to original image
Sharp = A + ConvImg;

minA = min(Sharp(:));
maxA = max(Sharp(:));
Sharp = (Sharp - minA) / (maxA - minA);

Sharp = imadjust(Sharp, [60/255 200/255], [0 1]);

figure
subplot(1,3,1); imshow(A); title('Original Image');
subplot(1,3,2); imshow(ConvImg); title('Laplacian filtered image');
subplot(1,3,3); imshow(Sharp); title('Sharpened Image');

%% Functions

% Histogram functions
function hist_img = my_histeq(im, L)
    % Forming 0's of length L.
    c = zeros(L, 1);
    for i = 0:L - 1
        c(i+1) = sum(sum(im == i));
    end
    
    p = c / (size(im, 1) * size(im, 2));    % Size of image
    s = (L-1) * cumsum(p);  % Cumulative hist of each pixel 
    s = round(s);           % CDF Of each pixel
    hist_img = uint8(zeros(size(im)));  % Convert size.
    for k=1:size(s,1)                   % Replace final value of each pixel
        hist_img(im == k-1) = s(k);
    end
end