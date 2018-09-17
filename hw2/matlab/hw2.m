%% DSP Homework 2 2.1-5

num = [.94 0 11.33 0 33.99];
den = [1 0.94 12.66 5.64 36];
H = tf(num,den)

bode(H, {0,10^2})
grid on;
figure;

%% DSP Homework 2 2.2-2

num2 = [1 -2];
den2 = [1 2];
H2 = tf(num2,den2)

bode(H2, {0,10^2})
grid on;
figure;

%% DSP Homework 2 2.3-3 a

num3 = [0 1000000000];
den3 = [1 100000];
H3 = tf(num3, den3)

bode(H3, {0, 10^7})
grid on;




