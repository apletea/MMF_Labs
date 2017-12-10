clc;
clear;

n = 10;
N = n;
var = 6;
%A = gallery('poisson', n);
%f = rand(N, 1);

for i=1:n    
    for j=1:n
        if i==j
            A(i,i) = 100 + i + var;
        else
            A(i,j) = i + j + var;
        end
    end
end

for i=1:N
    f(i) = i + 5 + var;
end

x = zeros(N, 1);

A
f = f'

r = A*x - f;
eps = 1.e-6;
normf = norm(f);
err = norm(r)/normf;
k = 0;
K_max = 1000;

while(err > eps && k < K_max)
    Ar = A*r;
    tau = (Ar.'*r)/(Ar.'*Ar);
    x = x - tau*r;
    r = A*x - f;
    err = norm(r)/normf;
    k = k + 1;
    Err(k) = err;
end

semilogy(1:k, Err)
k
A\f - x