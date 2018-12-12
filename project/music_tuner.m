%% DSP Final Project - Music Tuner

clear

% [y, Fs] = audioread('A4_piano_11025.wav');
Fs = 16000;
t = 0:1/Fs:.4;
Fbase = [27.50 29.13524 30.87 32.70320 34.64783 36.70810 41.20344 38.89087 43.65353 46.24930 48.99943 51.91309];
Ftest = [Fbase 2*Fbase 4*Fbase 8*Fbase 16*Fbase 32*Fbase 64*Fbase 128*Fbase(1) ...
    128*Fbase(2) 128*Fbase(3) 128*Fbase(4)];
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

noteNames = ["A0"; "Bb0"; "B0"; "C1"; "C#1"; "D1"; "Eb1"; "E1"; "F1"; "F#1"; 
             "G1"; "Ab1"; "A1"; "Bb1"; "B1"; "C2"; "C#2"; "D2"; "Eb2"; "E2"; "F2"; "F#2"; 
             "G2"; "Ab2"; "A2"; "Bb2"; "B2"; "C3"; "C#3"; "D3"; "Eb3"; "E3"; "F3"; "F#3"; 
             "G3"; "Ab3"; "A3"; "Bb3"; "B3"; "C4"; "C#4"; "D4"; "Eb4"; "E4"; "F4"; "F#4"; 
             "G4"; "Ab4"; "A4"; "Bb4"; "B4"; "C5"; "C#5"; "D5"; "Eb5"; "E5"; "F5"; "F#5"; 
             "G5"; "Ab5"; "A5"; "Bb5"; "B5"; "C6"; "C#6"; "D6"; "Eb6"; "E6"; "F6"; "F#6"; 
             "G6"; "Ab6"; "A6"; "Bb6"; "B6"; "C7"; "C#7"; "D7"; "Eb7"; "E7"; "F7"; "F#7"; 
             "G7"; "Ab7"; "A7"; "Bb7"; "B7"; "C8"];


fid = fopen('K22_Project_Framework/noteID.h','w');
fprintf(fid,'#define noteNumber %i \n',uint8(88));
fprintf(fid,'int centCorr[notenumber] = { \n');
for note = 1:87
    fprintf(fid,'%i, \n', -round(cents(note)));
end
fprintf(fid,'%i \n }; \n\n', -round(cents(note+1)));

fprintf(fid,'float freqInfo[notenumber] = { \n');
for note = 1:87
    fprintf(fid,'%f, \n', Ftest(note));
end
fprintf(fid,'%f \n }; \n\n', Ftest(note+1));
        
fprintf(fid,'const char *centKey[notenumber] = { \n');
for note = 1:87
    fprintf(fid,'"%s",\n', noteNames(note));
end
fprintf(fid,'"%s" }; \n', noteNames(note+1));
        
fclose(fid);
