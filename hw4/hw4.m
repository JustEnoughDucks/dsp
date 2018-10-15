%% DSP HW4 Problem 9 Part B

L = 3; M = 5; Omega = 4*pi/31; n = 0:30;

x9 = @(n) cos(Omega*n);

stem(n, x9(n));
xlabel('Sample');
ylabel('Magnitude');

n = 0:90;
x9up = @(n) x9(n/L);
figure;
stem(n, x9up(n));
xlabel('Sample');
ylabel('Magnitude');

n = 0:(30*3/5);
x9updown = @(n) x9up(M*n);
figure;
stem(n, x9updown(n));
xlabel('Sample');
ylabel('Magnitude');

%% DSP HW4 Problem 9 Part C

n = 0:30;

x9c = @(n) cos(Omega*n);
stem(n, x9c(n));
xlabel('Sample');
ylabel('Magnitude');

n = 0:6;
x9down = @(n) x9(n*M);
figure;
stem(n, x9down(n));
xlabel('Sample');
ylabel('Magnitude');

n = 0:(30*3/5);
x9downup = @(n) x9down(n/L);
figure;
stem(n, x9downup(n));
xlabel('Sample');
ylabel('Magnitude');

