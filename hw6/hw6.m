%% DSP Homework 6 
clear;

alphap = 1;
alphas = 20;
Fs = 10000;
omegap1 = 1000*2*pi;
omegap2 = Fs/2*2*pi - omegap1;
omegapLowProto = 1;
Omegap1 = omegap1/Fs;
Omegap2 = omegap2/Fs;
K = 50;
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
        pzDist(i) = sqrt(abs(real(pSort(q,1)) -real(zShape(i))) + abs(imag(pSort(q,1)) -imag(zShape(i))));
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

zplane(pzSort(:,[3 4]),pzSort(:,[1 2]));

A(K,3) = 0;
B(K,3) = 0;
for i = 1:K
    A(i,:) = poly(pzSort(i,[1 2]));
    B(i,:) = poly(pzSort(i,[3 4]));
end

B = single(real(bL/aK*prod(c2-zi)/prod(c2-pk).*B));
A = single(A);


fid = fopen('coef.h','w');
fprintf(fid,'#define NS %f \n',K);
fprintf(fid,'float A[NS][3] = { \n');
for ns = 1:K-1
	fprintf(fid,'{%f, %f, %f} ,\n', A(ns,1), A(ns,2), A(ns,3));
end
fprintf(fid,'{%f, %f, %f} \n};\n\n', A(K,1), A(K,2), A(K,3));

fprintf(fid,'float B[NS][3] = { \n');
for ns = 1:K-1
	fprintf(fid,'{%f, %f, %f} ,\n', B(ns,1), B(ns,2), B(ns,3));
end
fprintf(fid,'{%f, %f, %f} \n};', B(K,1), B(K,2), B(K,3));
fclose(fid);





% Hz = @(z) bL/aK*prod(c2-zi)/prod(c2-pk);
% for i = 1:K
%     Hz = @(z) Hz(z).*(1*z.^2 + 2*c1*zi(i)./(zi(i)-c2).*z + (zi(i)+c2)./(zi(i)-c2)) ...
%         ./(1*z.^2 + 2*c1*pk(i)./(pk(i)-c2).*z + (pk(i)+c2)./(pk(i)-c2))
%     
% end
% 
% Omegas = 2*atan(abs(roots([omegasLowProto omegap2Prewarp-omegap1Prewarp -omegasLowProto*omegap1Prewarp*omegap2Prewarp])))
% 
% Omega = 0:.001:pi; 
% 
% plot(Omega*Fs./(2*pi),abs(Hz(exp(j*Omega))));



% i = 1;
% barray(4,1) = 0;
% aarray(4,7) = 0;
% bQF(4,1)    = 0;
% aQF(4,1)    = 0;
% bits(4,1)   = 0;
% 
% 
% for q = 12:-2:6
%     for n = 1:32
%         bSearch = round(bi*2^n);
%         if abs(bSearch*20) > 2^(q - 2) && abs(bSearch*20) < 2^(q - 1)
%             barray(i,1) = bSearch;
%             bQF(i,1) = -n;
%         end
%         aSearch = round(aall(4)*2^n);
%         if abs(aSearch) > 2^(q -2) && abs(aSearch) < 2^(q - 1)
%             for k = 1:7
%                 aarray(i,k) = round(aall(k)*2^n);
%             end
%             aQF(i,1)    = -n;
%         end
%     end
%     bits(i,1) = q;
%     i = i + 1;
% end