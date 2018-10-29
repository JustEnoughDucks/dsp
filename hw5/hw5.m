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

% Part A
z = sym('z');
z5 = 0:.1:2*pi;

H2z1 = @(z) 0.03273793724*(z.^2 + 2*z + 1)/(z.^2-1.81915463768*z + 0.95522952077);
H2z2 = @(z) 0.01799913516*(z.^2 + 2*z + 1)/(z.^2-1.80572713311*z + 0.88054034430);
H2z3 = @(z) 0.00399530100*(z.^2 + 2*z + 1)/(z.^2-1.821397927591*z + 0.83800435313);

HzAcompressed = @(z) H2z1(z)*H2z2(z)*H2z3(z);

HzAmatlab = simplifyFraction(HzAcompressed(z),'Expand',true)

HzAwolfram = @(z) (2.35425*10^-6*z.^6 + 0.0000141255*z.^5 + 0.0000353138 *z.^4 ...
    + 0.000047085*z.^3 + 0.0000353138*z.^2 + 0.0000141255*z + 2.35425*10^-6) ... 
    /(z.^6 - 5.44628*z.^5 + 12.561*z.^4 - 15.6912*z.^3 + 11.1915*z.^2 - 4.31982*z + 0.704861)

zplane([2.35425*10^-6 0.0000141255 0.0000353138 0.000047085 0.0000353138 0.0000141255 2.35425*10^-6], ...
    [1 -5.44628 12.561 -15.6912 11.1915 -4.31982 0.704861]);

Hz5matlab = tf([2.35425*10^-6 0.0000141255 0.0000353138 0.000047085 0.0000353138 0.0000141255 2.35425*10^-6], ...
    [1 -5.44628 12.561 -15.6912 11.1915 -4.31982 0.704861]);

figure;
bode(Hz5matlab);

figure;
zplane([1761658490113586317846045285891716120828047375 10569950940681517907076271715350296724968284250 ...
    26424877351703794767690679288375741812420710625 35233169802271726356920905717834322416560947500 ...
    26424877351703794767690679288375741812420710625 10569950940681517907076271715350296724968284250 ...
    1761658490113586317846045285891716120828047375],[748288838313422294120286634350736906063837462003712 ...
    -4075390308631494457568399495402925982135208187527168 9399273497162929473779986189258117453387029733703680 ...
    -11741520959356998659883691203559529743502125373751296 8374508494806094059415556565110805732411398514950144 ...
    -3232472420013922650725117626402730041567267969251328 527439360973673617777959381850283328663024569189376]);
 
Hz5 = tf([1761658490113586317846045285891716120828047375 10569950940681517907076271715350296724968284250 ...
    26424877351703794767690679288375741812420710625 35233169802271726356920905717834322416560947500 ...
    26424877351703794767690679288375741812420710625 10569950940681517907076271715350296724968284250 ...
    1761658490113586317846045285891716120828047375],[748288838313422294120286634350736906063837462003712 ...
    -4075390308631494457568399495402925982135208187527168 9399273497162929473779986189258117453387029733703680 ...
    -11741520959356998659883691203559529743502125373751296 8374508494806094059415556565110805732411398514950144 ...
    -3232472420013922650725117626402730041567267969251328 527439360973673617777959381850283328663024569189376]);

figure;
bode(Hz5);
% plot(z5, abs(H2z1(exp(j*z5))*H2z2(exp(j*z5))*H2z3(exp(j*z5))));