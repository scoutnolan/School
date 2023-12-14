%% Nolan Anderson
% EE 384 
% Classwork 5
% Due 23 September 2021
clear all; clc; close all;

%% Problem 1:
% Basic read and write images

% ----- a -----
% Pull in image
A = imread('lena.bmp');
figure
imshow(A), title('1a Lena RGB');

% ----- b -----
% Turn image to gray scale
B = rgb2gray(A);
figure
imshow(B), title('1b Lena GrayScale');

% ----- c -----
% Create your own grayscale function
gray = 0.3*A(:,:,1) + 0.6 * A(:,:,2) + 0.1*A(:,:,2);
figure
imshow(gray), title('1b Lena GrayScale (function)');

% ----- d -----
% Write out image
imwrite(gray, 'lena_gray.jpg');

%% Problem 2:
%  Histogram equalization (enhance the contrast of an image)

% ----- a -----
% Read and show the image lowcontrast.jpg.
C = imread('lowcontrast.jpg');
figure
imshow(C), title('2a Low contrast jpg');

% ----- b -----
% Show the histogram of the image using the function imhist
figure
imhist(C), title('2b Low Constrast Historgram');

% ----- c -----
% Using the function histeq to enhance contrast using histogram equalization, show the
% histogram and the image after enhancing.
D = histeq(C);
figure
imshow(D), title('2c Histogram equalization');
figure
imhist(D), title('2c Histogram equalization');

%% Problem 3:

% ----- a -----
% Add salt-and-pepper noise to the lena’s gray-scale image using the function imnoise.
% Assume that the noise density is 0.05 (read the function’s documentation for more
% information). Show the noisy image
I = imread('lena_gray.jpg');
J = imnoise(I, 'salt & pepper', 0.05);
figure
imshow(J), title('3a salt & pepper');

% ----- b -----
% Filter the noise using the function medfilt2 with the 3x3 window, show the filtered image.
K = medfilt2(J);
figure
imshowpair(J, K, 'montage'), title('3b Noise filter');

% ----- c -----
% Filter the noise with the 5x5 window and show the filtered image; compare the filtered
% image to that of 3b). What happen when we increase the window size in the median
% filter?
M = medfilt2(J, [5 5]);
figure
imshowpair(J, M, 'montage'), title('3c 5x5 window');