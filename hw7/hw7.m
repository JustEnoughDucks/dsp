%% DSP Homework 7 Matlab Code
T = 1/20000;
Omegap = 2*pi*7000*T;    Omegas = 2*pi*9000*T; 
Lh = 141; 
K = 10*Lh; 
k = (0:K-1);
Omegak = k*2*pi/K;

OmegaPC = 2*pi*1500*T;   OmegaPR = 2*pi*3000*T;
parablength = Omegak.*(Omegak>=0 & Omegak<=OmegaPR);
% OmegaPC = 2*pi*750*T;   OmegaPR = 2*pi*1500*T;
% parablength = Omegak.*(Omegak>=Omegap & Omegak<=OmegaPR);

sawPer = 1000*2*pi/20000;
xsawPer= Omegak.*(Omegak > OmegaPR);

sinfn = (.7943-.707)*sawtooth(1/sawPer*xsawPer) + .7;
% sinfn = ((xsinPer - OmegaPC).^2).*sawtooth(1/sinPer*xsinPer) + .7943;
plot(xsawPer, sinfn);


figure;
xsauce = [0 OmegaPC OmegaPR]; ysauce = [.7943 .8915 .7943]; psauce = polyfit(xsauce,ysauce,2);
xu=linspace(0,OmegaPR,10);
parabola = [polyval(psauce,parablength)];
plot(parablength, parabola)

Q = 1.0*(Omegak<=OmegaPR) + 1.0*(Omegak>=OmegaPR & Omegak <= Omegap) + ...
    .01*(Omegak>Omegap & Omegak <= Omegas) + 10.0*(Omegak>=Omegas);
Q(fix(K/2)+2:end) = Q(round(K/2):-1:2);

Hd = (0.*(Omegak>Omegap) + parabola.*(Omegak>=0 & Omegak<=OmegaPR) ...
     + sinfn.*(Omegak >= OmegaPR & Omegak <= Omegap)).*exp(-1j*k*pi*(Lh-1)/K);
Hd(fix(K/2)+2:end) = conj(Hd(round(K/2):-1:2));
l = (0:Lh-1)'; a = exp(1j*l*Omegak)*Q.'/K; b = exp(1j*l*Omegak)*(Hd.*Q/K).';
a = real(a); b = real(b);
A = toeplitz(a); h = (A\b);
n = (0:Lh-1)'; 
subplot(211); 
stem(n,h);
Omega = linspace(0,pi,1001); 
H = polyval(h,exp(1j*Omega)).*exp(-1j*(Lh-1)*Omega);
subplot(212); 
plot(Omega,20*log10(abs(H)))
deltap = 2*max(abs(abs(H(Omega>=Omegap))-1))
deltas = max(abs(H(Omega<=Omegas)))

figure;
plot(Q);

Morder = length(h);
[hMax,hMaxIndex] = max(h)
% scale = abs((2^(16-1)-50)/h(hMaxIndex-1))
scale = abs((2^15)/(abs(sum(h))));                                      %Q notation
scale = 2.^nextpow2(scale)
hInt = floor(h*(scale));

figure;
subplot(211); 
stem(n,hInt);
Omega = linspace(0,pi,1001); 
H = polyval(hInt,exp(1j*Omega)).*exp(-1j*(Lh-1)*Omega);
subplot(212); 
plot(Omega,20*log10(abs(H)))
deltap = 2*max(abs(abs(H(Omega>=Omegap))-1))
deltas = max(abs(H(Omega<=Omegas)))

        fid = fopen('K22_Project_Framework/coef.h','w');
        fprintf(fid,'#define Korder %i \n',uint8(Morder));
        fprintf(fid,'int h[Korder] = { \n');
        for Korder = 1:Morder-1
            fprintf(fid,'%i,\n', hInt(Korder));
        end
        fprintf(fid,'%i }; \n', hInt(Korder));
        fclose(fid);

save('bpg.mat','hInt');
