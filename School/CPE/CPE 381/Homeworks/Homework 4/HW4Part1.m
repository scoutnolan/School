n1 = [0 0 0 0];
d1 = [0 0 0 0]; 
figure(1) 
m=20;
freqresp_s(n1,d1,m)

n2 = [0 0 0 0]; 
d2 = [0 0 0 0];
figure(2)
freqresp_s(n2,d2,m)

n3 = [0 0 0 0]; 
d3 = [0 0 0 0];
figure(3) 
freqresp_s(n3,d3,m)

function[w,Hm,Ha]=freqresp_s(b,a,max)
w = 0:0.01:max;
H = freqresp_ss(b,a,w);
Hm = abs(H);
Ha = angle(H)*180/pi;
figure
subplot(311)
plot(w,Hm)
subplot(312)
plot(w,Ha)
subplot(313)
splane(b,a)
end

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
stem(real(z),imag(z),'o:')
hold on
stem(real(p),imag(p),'x:')
hold on
grid
axis([min(im) max(im) min(im) max(im)]);
hold off
end