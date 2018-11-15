%% DSP Homework 6 
clear;

K = 110;
z = 0;

matArrayA(4,K,3) = 0;
matArrayB(4,K,3) = 0;

for fp = [250 500 1000 2000]
    
    z = z + 1; % Iteration counter
    alphap = 1;
    alphas = 20;
    Fs = 10000;
    omegap1 = fp*2*pi;
    omegap2 = Fs/2*2*pi - omegap1;
    omegapLowProto = 1;
    Omegap1 = omegap1/Fs;
    Omegap2 = omegap2/Fs;
    k = 1:K;

    omegasLowProto = omegapLowProto*cosh(acosh(sqrt((10^(alphas/10)-1)/(10^(alphap/10)-1)))/K);
    epsilon = 1/sqrt(10^(alphas/10)-1);

    pk = -omegapLowProto*sinh(asinh(1/epsilon)/K)*sin(pi*(2*k-1)/(2*K))+...
    1j*omegapLowProto*cosh(asinh(1/epsilon)/K)*cos(pi*(2*k-1)/(2*K));

    pk = omegapLowProto*omegasLowProto./pk;

    zi = 1j*omegasLowProto.*sec(pi*(2*k-1)/(2*K));
    bL = prod(pk./zi);
    aK = 1; 
    L = length(zi); 
    K = length(pk);

    omegap1Prewarp = tan(Omegap1/2);
    omegap2Prewarp = tan(Omegap2/2);

    c1 = (omegap1Prewarp*omegap2Prewarp-1)/(omegap1Prewarp*omegap2Prewarp+1);
    c2 = (omegap2Prewarp-omegap1Prewarp)/(omegap1Prewarp*omegap2Prewarp+1);


    for i = 1:L
        Zdig(i,:) = roots([1 2*c1*zi(i)./(zi(i)-c2) (zi(i)+c2)./(zi(i)-c2)]);
        Zcoef(i,:) = [1 2*c1*zi(i)./(zi(i)-c2) (zi(i)+c2)./(zi(i)-c2)];
    end
    for i = 1:K 
        Pdig(i,:) = roots([1 2*c1*pk(i)./(pk(i)-c2) (pk(i)+c2)./(pk(i)-c2)]);
        Pcoef(i,:) = [1 2*c1*pk(i)./(pk(i)-c2) (pk(i)+c2)./(pk(i)-c2)];
    end

    zShape = reshape(Zdig,[L*2, 1]);
    pShape = reshape(Pdig,[K*2, 1]);
    pShape = cplxpair(pShape);
    pDist = abs(pShape(:));
    pSort = [pShape pDist];
    pSort = sortrows(pSort, [2 1], 'descend', 'ComparisonMethod','real');

    pzSort(K,4) = 0;
    b = false;
    r = 1;
    for q = 1:2*K
        b = ~b;
        for i = 1:size(zShape)
            pzDist(i) = sqrt(abs(real(pSort(q,1)) -real(zShape(i))).^2 + abs(imag(pSort(q,1)) -imag(zShape(i))).^2);
        end
        [M, I] = min(pzDist);
        if(b)
            pzSort(r,[1 3]) = [pSort(q,1) zShape(I)];
        elseif(~b)
            pzSort(r,[2 4]) = [pSort(q,1) zShape(I)];
            r = r + 1;
        end
        zShape(I) = [];
        pzDist(I) = [];
    end

    figure;
    zplane(pzSort(:,[3 4]),pzSort(:,[1 2]));
    hold on
    for i = 1:K
        plot([real(pzSort(i,1)) real(pzSort(i, 2)),], ...
        [imag(pzSort(i,1)) imag(pzSort(i, 2))], 'color', [1/(K+.1*K)*(i) 1/(K+.1*K)*i 1/(K+.1*K)*i]);
        plot([real(pzSort(i,2)) real(pzSort(i, 4)),], ...
        [imag(pzSort(i,2)) imag(pzSort(i, 4))], 'color', [1/(K+.1*K)*(i) 1/(K+.1*K)*i 1/(K+.1*K)*i]);
        plot([real(pzSort(i,1)) real(pzSort(i, 3)),], ...
        [imag(pzSort(i,1)) imag(pzSort(i, 3))], 'color', [1/(K+.1*K)*(i) 1/(K+.1*K)*i 1/(K+.1*K)*i]);
    end

    Acoef(K,3) = 0;
    Bcoef(K,3) = 0;
    for i = 1:K
        Acoef(i,:) = poly(pzSort(i,[1 2]));
        Bcoef(i,:) = poly(pzSort(i,[3 4]));
    end

    gain = single(nthroot(real((bL/aK*prod(c2-zi)/prod(c2-pk))),K));
    Bcoef = single(gain*Bcoef);
    Acoef = single(Acoef);
    Bcoef = flipud(Bcoef);
    Acoef = flipud(Acoef);
    Acoef(:,1) = [];
    Bcoef(:,3) = [];

    if fp == 250
        fid = fopen('K22_Project_Framework/coef.h','w');
        fprintf(fid,'#define Korder %i \n',uint16(K));
    else
        fid = fopen('K22_Project_Framework/coef.h','a');
    end
        fprintf(fid,'float A%i[Korder][2] = { \n',z);
        for Korder = 1:K-1
            fprintf(fid,'{%f, %f} ,\n', Acoef(Korder,1), Acoef(Korder,2));
        end
        fprintf(fid,'{%f, %f} \n};\n\n', Acoef(K,1), Acoef(K,2));

        fprintf(fid,'float B%i[Korder][2] = { \n',z);
        for Korder = 1:K-1
            fprintf(fid,'{%f, %f} ,\n', Bcoef(Korder,1), Bcoef(Korder,2));
        end
        fprintf(fid,'{%f, %f} \n};\n\n', Bcoef(K,1), Bcoef(K,2));
        fclose(fid);
        

    %% Homework 6 Problem 2 Simulation

    ADCval = 1;
    yn(K+1) = 0;
    s(K,2) = 0;

    figure;
    for t = 0:.0001:.005

    %     Yn(1,1) = 4095;
    %     if(t ~= 0)
    %         Yn(1,1) = 0;
    %     end

        Yn(1,1) = 2048*sin(500*2*pi*t) + 2047;

        for k = 1:K
                Yn(k+1) = Bcoef(k,1)*Yn(k) + s(k,1);
                s(k,1) = Bcoef(k,2)*Yn(k) - Acoef(k,1)*Yn(k+1) + s(k,2);
                s(k,2) = Bcoef(k,1)*Yn(k) - Acoef(k,2)*Yn(k+1);
        end
        valDAC = Yn(K+1);

        stem(t,abs(valDAC));
        hold on
    end
    hold off




    figure;
    Hz = @(z) 1;
    for k = 1:K
        Hz = @(z) Hz(z).*(Bcoef(k,1)*z.^2 + Bcoef(k,2).*z + Bcoef(k,1)) ...
            ./(1*z.^2 + Acoef(k,1).*z + Acoef(k,2));

    end

    Omegas = 2*atan(abs(roots([omegasLowProto omegap2Prewarp-omegap1Prewarp -omegasLowProto*omegap1Prewarp*omegap2Prewarp])))

    Omega = 0:.001:pi; 

    plot(Omega*Fs./(2*pi),abs(Hz(exp(j*Omega))));
    title('Frequency Response plot using Coefficient Array');
    
    
    % Wrong way to implement it. It shoud be Arrary(columns, rows, page)
    % but is specified as Array(page, row, column)
    
    OnesArray(length(Acoef(:,1)),1) = 1;
    A(z,:,:) = [OnesArray(:,1),Acoef(:,1),Acoef(:,2)];
    B(z,:,:) = [Bcoef(:,1), Bcoef(:,2), Bcoef(:,1)];

end

save('bpg.mat','A','B');