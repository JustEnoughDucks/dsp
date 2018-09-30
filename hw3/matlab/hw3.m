%DSP Homework 3 Problem 5
A = 5;
B = 2;
T = 40;

t = -.05:.0001:.05;
x = @(t) 0.*(heaviside(t+20)-heaviside(t+12)) + -t./(12).*(heaviside(t+12)-heaviside(t)) + ...
    2*t/15.*(heaviside(t)-heaviside(t-15)) + 0.*(heaviside(t-15) - heaviside(t-20));
plot(t, x(t) + x(t-40))
figure;

c1 = .4206;
c2 = 1.319;
c3 = 1;

K = [-10:.01:10];

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
Xk0 = 1/T.*((10+B)/2 + (10+A));

Yk = @(K) Xk(K).*c2.*(K ~= 0);
Yk0 = (c1 + c2.*Xk0);

subplot(1,2,2);
plot(K, abs(Yk(K)));
figure;

yk = 0.*t;
yk = yk + (c1 + c2.*Xk0);

ykMag = zeros(10,1);
ykTheta = zeros(10,1);

for K = 1:10
    
    ak = real(Yk(K));
    bk = -imag(Yk(K));
    ykMag(K) = sqrt(ak^2 + bk^2);
    ykTheta(K) = atan2(-bk,ak);
    
    yk = yk + ykMag(K).*cos(1000*omega0*K*t + ykTheta(K));
    
    fprintf('K=%i, ykmin=%d, ykmax=%d\n', K, min(yk), max(yk));
    plot(t, abs(yk));
    hold on
end
ykMag
ykTheta
figure;


%% Homework 5 Board simulation
f = c3/40;

sumval = (c1 + c2.*Xk0);
K = 10;
for t = 0:.0001:.006
    for k = 1:K
        sumval = ykMag(k)*cos((k)*20000*omega0*t + ykTheta(k)) + sumval;
    end
	
	valDAC = sumval*4095/3;

    stem(t,abs(valDAC));
    hold on

% 	if(t > (1/f))
% 		i = 0;
%     end
% 	
% 	i++;
% 	t = i * .0001f;
end

