%% DSP Homework 5 Problem 3 6.3-8
T3 = 1/10;

omega3 = -pi:.01:pi;

Hz3 = @(z) T3/2.*(1+z.^-1)./(1-z.^-1);

plot(omega3, abs(Hz3(exp(j.*omega3))));
xlabel('Frequency (Omega)');
title('Magnitude of H(jw) from H(Z)');
axis([-pi pi 0 20]);
figure;
plot(omega3, angle(Hz3(exp(j.*omega3))));
xlabel('Frequency (Omega)');
title('Angle of H(jw) from H(Z)');
axis([-pi pi -pi pi]);

% Part A
Xz3a = @(z) z.*(z-.995)./(z.^2 - 1.99*z + 1)

figure;
plot(omega3, abs(Hz3(exp(j.*omega3)).*Xz3a(exp(j.*omega3))));
xlabel('Frequency (Omega)');
title('Magnitude of H(w)*Xa(w) from H(Z)');
axis([-pi pi 0 20]);
figure;
plot(omega3, angle(Hz3(exp(j.*omega3)).*Xz3a(exp(j.*omega3))));
xlabel('Frequency (Omega)');
title('Angle of H(w)*Xa(w) from H(Z)');
axis([-pi pi -pi pi]);

% Part B
Xz3b = @(z) .5*z./(z.^2 - 1.732*z + 1)

figure;
plot(omega3, abs(Hz3(exp(j.*omega3)).*Xz3b(exp(j.*omega3))));
xlabel('Frequency (Omega)');
title('Magnitude of H(w)*Xb(w) from H(Z)');
axis([-pi pi 0 50]);
figure;
plot(omega3, angle(Hz3(exp(j.*omega3)).*Xz3b(exp(j.*omega3))));
xlabel('Frequency (Omega)');
title('Angle of H(w)*Xb(w) from H(Z)');
axis([-pi pi -pi pi]);

% Part C
Xz3c = @(z) z.^2./(z.^2 + 1)

figure;
plot(omega3, abs(Hz3(exp(j.*omega3)).*Xz3c(exp(j.*omega3))));
xlabel('Frequency (Omega)');
title('Magnitude of H(w)*Xc(w) from H(Z)');
axis([-pi pi 0 50]);
figure;
plot(omega3, angle(Hz3(exp(j.*omega3)).*Xz3c(exp(j.*omega3))));
xlabel('Frequency (Omega)');
title('Angle of H(w)*Xc(w) from H(Z)');
axis([-pi pi -pi pi]);

%% DSP Hoework 5 Problem 5 6.5-2
t5 = 0:.00001:.001;
B5 = 10000*pi;
T5 = 10^-4;
omega5 = 1:1:1/(T5);

% Part A

xc5 = @(t) sinc(B5*t/pi);
Xc5 = @(omega) T5*(heaviside(omega)-heaviside(omega-1/(T5*2)));

figure;
plot(t5, xc5(t5));
xlabel('Time (s)');
title('Input Signal to C/D');
figure;
plot(omega5, abs(Xc5(omega5)));
xlabel('Frequency (omega)');
title('Input Spectra to C/D');
% figure;
% plot(omega5, angle(Xc5(omega5)));
% xlabel('Frequency (omega)');
% ylabel('Angle (rads)');
% title('Input Spectra to C/D');

% Part B
n5 = 0:1:10;
xd5 = @(n5) sinc(B5*n5*T5/pi);

figure;
stem(n5, xd5(n5));
xlabel('Samples');
title('Input signal for H(Omega)');

Omega5 = -pi:.01:pi;
X5 = @(Omega5) pi* (heaviside(Omega5 + pi/2) - heaviside(Omega5 - pi/2));

figure;
plot(Omega5, abs(X5(Omega5)));
xlabel('Frequency (Omega))');
title('Input Spectra for H(Omega)');
% figure;
% plot(Omega5, angle(Xd5(Omega5)));
% xlabel('Frequency (Omega))');
% title('Input Spectra for H(Omega)');

% Part C
H5 = @(Omega5) j*Omega5/T5;
Y5 = @(Omega5) X5(Omega5).*H5(Omega5);

figure;
plot(Omega5, abs(Y5(Omega5)));
xlabel('Frequency (Omega)');
title('Output Spectra for H(Omega)');
figure;
plot(Omega5, angle(Y5(Omega5)));
xlabel('Frequency (Omega)');
ylabel('Angle (rads)');
title('Output Spectra angle for H(Omega)');

yd5 = @(n5) 1/(2*pi*T5).*(pi.*n5.*cos(pi*n5/2) - 2*sin(pi*n5/2))./n5.^2;

figure;
stem(n5, yd5(n5));
xlabel('Samples');
ylabel('Amplitude');
title('Output signal for H(Omega)');

% Part D

yc5 = @(t) yd5(t/T5);

figure;
plot(t5, yc5(t5));
xlabel('Time (s)');
ylabel('Amplitude');
title('Output signal');

%% DSP Homework 5 PRoblem 9 7.7-2

Fs9 = 100/pi;
T9 = 1/Fs9;

% Part A
Omega9 = 0:.01:pi/2;

b1 = 0.03273793724;
b2 = 0.01799913516;
b3 = 0.00399530100;
a1a = -1.81915463768;
a1b = 0.95522952077;
a2a = -1.80572713311;
a2b = 0.88054034430;
a3a = -1.821397927591;
a3b = 0.83800435313;


b12 = conv([1 2 1],[1 2 1]);
ball = conv([b12],[1 2 1])
bi = b1*b2*b3;

a12 = conv([1 a1a a1b],[1 a2a a2b]);
aall = conv([a12],[1 a3a a3b]);

H9z = @(z) bi*(1 + ball(2)*z.^-1 + ball(3)*z.^-2 + ball(4)*z.^-3 + ...
    ball(5)*z.^-4 + ball(6)*z.^-5 + ball(7)*z.^-6)./(1 + aall(2)*z.^-1 ...
    + aall(3)*z.^-2 + aall(4)*z.^-3 + aall(5)*z.^-4 + aall(6)*z.^-5 + aall(7)*z.^-6);


H9ztf = tf(bi*ball,aall)

% Part B
figure;
plot(Omega9./T9, abs(H9z(exp(Omega9*j))));
title('Magnitude of H(z) Expanded');
xlabel('Frequency (Omega)');
ylabel('Amplitude');
% bode(H9ztf);

i = 1;
barray(4,1) = 0;
aarray(4,7) = 0;
bQF(4,1)    = 0;
aQF(4,1)    = 0;
bits(4,1)   = 0;


% Part C
for q = 12:-2:6
    for n = 1:32
        bSearch = round(bi*2^n);
        if abs(bSearch*20) > 2^(q - 2) && abs(bSearch*20) < 2^(q - 1)
            barray(i,1) = bSearch;
            bQF(i,1) = -n;
        end
        aSearch = round(aall(4)*2^n);
        if abs(aSearch) > 2^(q -2) && abs(aSearch) < 2^(q - 1)
            for k = 1:7
                aarray(i,k) = round(aall(k)*2^n);
            end
            aQF(i,1)    = -n;
        end
    end
    bits(i,1) = q;
    i = i + 1;
end

totalArray = cat(2, bits, barray, bQF, aarray, aQF)
coefTable = array2table(totalArray, 'VariableNames', {'Quant_bit','b0', 'b_2_Scale_Fac', ... 
    'a0','a1','a2','a3','a4','a5','a6','a_2_Scale_Fac'})

% for k = 1:4
%     figure;
%     b0Sauce = barray(k)*2^(bQF(k));
%     aSauce = 2^(aQF(k));
%     zplane([b0Sauce b0Sauce*ball(2) b0Sauce*ball(3) b0Sauce*ball(4) b0Sauce*ball(5) ...
%         b0Sauce*ball(6) b0Sauce*ball(7)],[aSauce*aarray(k,1) aSauce*aarray(k,2) ...
%         aSauce*aarray(k,3) aSauce*aarray(k,4) aSauce*aarray(k,5) aSauce*aarray(k,6) ...
%         aSauce*aarray(k,7)]);
%     title(['Pole-Zero plot for quantization ' num2str(bits(k)) ' bits']);
%     
% end

figure;
zplane([ball(1) ball(2) ball(3) ball(4) ball(5) ball(6) ball(7)], ... 
    [aall(1) aall(2) aall(3) aall(4) aall(5) aall(6) aall(7)]);
title('Original Pole-Zero plot before quantization');

for k = 1:4
    H9zQuantized = @(z) barray(k)*2^(bQF(k)).*(1 + ball(2)*z.^-1 + ball(3)*z.^-2 + ball(4)*z.^-3 + ...
        ball(5)*z.^-4 + ball(6)*z.^-5 + ball(7)*z.^-6)./(2^(aQF(k))*(aarray(k,1) + aarray(k,2)*z.^-1 ...
        + aarray(k,3)*z.^-2 + aarray(k,4)*z.^-3 + aarray(k,5)*z.^-4 + aarray(k,6)*z.^-5 + aarray(k,7)*z.^-6));

    figure;
    plot(Omega9, abs(H9zQuantized(exp(j*Omega9))));
    title(['Magnitude plot for quantization ' num2str(bits(k)) ' bits']);
    xlabel('Frequency (Omega)');
end

i = 1;
barray2(10,1) = 0;
aarray2(10,7) = 0;
bQF2(10,1)    = 0;
aQF2(10,1)    = 0;
bits2(10,1)   = 0;

for q = 15:24
    for n = 1:256
        bSearch = round(bi*2^n);
        if abs(bSearch*20) > 2^(q - 2) && abs(bSearch*20) < 2^(q - 1)
            barray2(i,1) = bSearch;
            bQF2(i,1) = -n;
        end
        aSearch = round(aall(4)*2^n);
        if abs(aSearch) > 2^(q -2) && abs(aSearch) < 2^(q - 1)
            for k = 1:7
                aarray2(i,k) = round(aall(k)*2^n);
            end
            aQF2(i,1)    = -n;
        end
    end
    bits2(i,1) = q;
    i = i + 1;
end

for k = 1:10
    figure;
    b0Sauce2 = barray2(k)*2^(bQF2(k));
    aSauce2 = 2^(aQF2(k));
    zplane([b0Sauce2 b0Sauce2*ball(2) b0Sauce2*ball(3) b0Sauce2*ball(4) b0Sauce2*ball(5) ...
        b0Sauce2*ball(6) b0Sauce2*ball(7)],[aSauce2*aarray2(k,1) aSauce2*aarray2(k,2) ...
        aSauce2*aarray2(k,3) aSauce2*aarray2(k,4) aSauce2*aarray2(k,5) aSauce2*aarray2(k,6) ...
        aSauce2*aarray2(k,7)]);
    title(['Pole-Zero plot for quantization ' num2str(bits2(k)) ' bits']);
    
end