Omegap = pi/2; Omegas = 3*pi/8;
Lh = 101; K = 10*Lh; k = (0:K-1); Omegak = k*2*pi/K;
Q = 10.0*(Omegak<=Omegas)+1.0*(Omegak>=Omegap);
Q(fix(K/2)+2:end) = Q(round(K/2):-1:2);
Hd = 1.0*(Omegak>=Omegap).*exp(-1j*k*pi*(Lh-1)/K);
Hd(fix(K/2)+2:end) = conj(Hd(round(K/2):-1:2));
l = (0:Lh-1)'; a = exp(1j*l*Omegak)*Q.'/K; b = exp(1j*l*Omegak)*(Hd.*Q/K).';
A = toeplitz(a); h = (A\b);
n = (0:Lh-1)'; subplot(211); stem(n,h);
Omega = linspace(0,pi,1001); H = polyval(h,exp(1j*Omega)).*exp(-1j*(Lh-1)*Omega);
subplot(212); plot(Omega/pi,20*log10(abs(H)));
deltap = 2*max(abs(abs(H(Omega>=Omegap))-1))
deltas = max(abs(H(Omega<=Omegas)))

figure;
plot(Q);