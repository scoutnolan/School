%% Header
% Nolan Anderson
% CPE 381 - 01 Homework 4 # 1
clear all; clf
m = 10;
%% H1
n1 = [0 1 0 4*pi^2]; 
d1 = [1 -2 2.25+4*pi^2 4*pi^2+0.25]; 
figure(1)
freq(n1,d1,m);

%% H2
n2 = [1 -3 3+4*pi^2 -(4*pi^2-1)]; 
d2 = [1 3 3+4*pi^2 4*pi^2-1];   
figure(2) 
freq(n2,d2,m);

%% H3
n3 = [0 0 1 -1]; 
d3 = [1 3 4*pi^2+3 4*pi^2+1]; 
figure(3) 
freq(n3,d3,m);

%% Frequency Function
function[w,Hm,Ha]=freq(b,a,max)
    w = 0:0.01:max;
    H = freqs(b,a,w);
    Hm = abs(H);
    Ha = angle(H)*180/pi;
    subplot(311);
    plot(w,Hm);
    subplot(312);
    plot(w,Ha);
    subplot(313);
    splane(b,a);
end

%% Splane function
function splane(num,den)
    z=roots(num);
    p=roots(den);
    A1=[min(imag(z)) min(imag(p))];A1=min(A1)-1;
    B1=[max(imag(z)) max(imag(p))];B1=max(B1)+1;
    N=20;
    D=(abs(A1)+abs(B1))/N;
    im=A1:D:B1;
    Nq=length(im);
    re=zeros(1,Nq);
    A=[min(real(z)) min(real(p))];A=min(A)-1;
    B=[max(real(z)) max(real(p))];B=max(B)+1;
    stem(real(z),imag(z),'o:');
    hold on
    stem(real(p),imag(p),'x:');
    hold on
    grid
    axis([min(im) max(im) min(im) max(im)]);
    hold off
end

