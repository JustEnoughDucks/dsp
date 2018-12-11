%% DSP Final Project - Music Tuner

clear

% [y, Fs] = audioread('A4_piano_11025.wav');
Fs = 16000;
t = 0:1/Fs:.4;
Fbase = [27.50 30.87 32.70320 36.70810 41.20344 43.65353 48.99943];
Ftest = [Fbase 2*Fbase 4*Fbase 8*Fbase 16*Fbase 32*Fbase 64*Fbase 128*Fbase(1) ...
    128*Fbase(2) 128*Fbase(3)];
cents(length(Ftest)) = 0;
f0(length(Ftest)) = 0;
bufferSize = 2048;
yinBuffer(bufferSize) = 0;
count = 1;

for Freq = Ftest
    z = 1023*exp(-t).*sin(Freq*2*pi*t) + 1023;
    halfBuffer = .5*bufferSize;
    buffer = z(1:bufferSize);
    sum = 0;
    threshold = .3; % From YIN paper
    minTau = 1;
    tolerance = .01;

    % Step 2 (Step 1 is voided by this difference equation): 
    % Calculate the difference equation for half of samples
    for tau = 1:halfBuffer

    % Take the difference of the signal with a shifted version of itself, then square it.
    % Yin special method of autocorrelation start
        for i = 1:halfBuffer
            delta = buffer(i) - buffer(i + tau);
            yinBuffer(tau) = yinBuffer(tau) + delta * delta;
        end
    end

    % Step 3: Calculate the normalized mean of the normalized difference

    yinBuffer(1) = 1; % No shift will obviously be normalized to 1 as it is perfect correlation

    for tau = 2:halfBuffer
        sum = sum + yinBuffer(tau);
        yinBuffer(tau) = yinBuffer(tau)*tau/sum;
    end

    % Step 4: Set absolute threshold smallest value of tau that gives a minimum
    % of deltaYIN deeper  than  that  threshold. (Cheveigne)
    % Essentially, we have to find the first local minima below the threshold

    for tau = 2:halfBuffer
        if(yinBuffer(tau) < threshold)
            if(tau + 1 < halfBuffer && yinBuffer(tau) < yinBuffer(tau - 1) ...
                    && yinBuffer(tau + 1) > yinBuffer(tau) && yinBuffer(tau) < yinBuffer(minTau))
                minTau = tau;
                break;
            end
        end 
    end
    if (minTau == 0)
        minTau = 1;
    end

    % Step 5: Interpolate
    if(minTau > 0)

        if minTau - 1 < 1
            a = minTau;
        else
            a = minTau - 1;
        end
        if minTau + 1 > bufferSize
            c = minTau;
        else
            c = minTau + 1;
        end
        b = minTau;
        fa = yinBuffer(a);
        fb = yinBuffer(minTau);
        fc = yinBuffer(c);

    %     while (steps_taken < 16 & abs(x1-x0) > tolerance)
    %         x2 = x1 - ( (f(x1) * (x1 - x0)) / (f(x1) - f(x0)) )
    %         x1 = x2;
    %         x0 = x1;
    %         steps_taken = steps_taken + 1;
    %     end
        newpoint = minTau + (fa - fc) / (2 * (fa - 2*fb + fc));
        f0(count) = Fs/newpoint;
    else
        f0 = 0;
    end

    % Step 6: Calculate whether the signal is sharp or flat and by what margin

    cents(count) = 1200*log2(f0(count)/Freq);

    count = count + 1;

end
