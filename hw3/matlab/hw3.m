%DSP Homework 3 Problem 5
A = 5;
B = 2;
T = 40;

t = -20:.1:60;
x = @(t) 0.*(heaviside(t+20)-heaviside(t+12)) + -t./(12).*(heaviside(t+12)-heaviside(t)) + ...
    2*t/15.*(heaviside(t)-heaviside(t-15)) + 0.*(heaviside(t-15) - heaviside(t-20));
plot(t, x(t) + x(t-40))
figure;

c1 = 1.5;
c2 = 1.90;
c3 = 1;



K = [-20: .01: 20];

omega0 = 2*pi/T;

Xk = @(K) 1./(T*omega0.^2 .*K.^2) .* (-1/(10+B) - 2/(10 + A) + (1/(10+B) - ...
    j*omega0*K).*exp(j*omega0*K*(10+B)) + (2./(10+A) + 2*j*omega0*K).*...
    exp(-j*omega0*K*(10 + A))) .*(K ~= 0) + 1/T.*((10+B)/2 + 10+A).*(K == 0);

plot(K, abs(Xk(K)));
figure;

omega0 = c3*2*pi/T;

Xk = @(K) 1./(T*omega0.^2 .*K.^2) .* (-1/(10+B) - 2/(10 + A) + (1/(10+B) - ...
    j*omega0*K).*exp(j*omega0*K*(10+B)) + (2./(10+A) + 2*j*omega0*K).*...
    exp(-j*omega0*K*(10 + A))) .*(K ~= 0) + 1/T.*((10+B)/2 + 10+A).*(K == 0);

Yk = @(K) Xk(K).*c2.*(K ~= 0) + (c1 + c2.*Xk(K)).*(K == 0)

subplot(1,2,1)
plot(K, abs(Yk(K)));

omega0 = 1*2*pi/T;

Xk = @(K) 1./(T*omega0.^2 .*K.^2) .* (-1/(10+B) - 2/(10 + A) + (1/(10+B) - ...
    j*omega0*K).*exp(j*omega0*K*(10+B)) + (2./(10+A) + 2*j*omega0*K).*...
    exp(-j*omega0*K*(10 + A)));

Yk = @(K) Xk(K).*c2.*(K ~= 0) + (c1 + c2.*Xk(K)).*(K == 0)

subplot(1,2,2);
plot(K, abs(Yk(K)));
figure;

yk = 0.*t;
yk = yk + (c1 + c2.*Xk(0));
for K = 1:10
    yk = yk + Yk(K).*exp(1j*K*omega0*t) + Yk(-K).*exp(-1j*K*omega0*t);
end

plot(t, yk);
