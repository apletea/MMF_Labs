clc;
clear;

n = 20;
N = n^2;
var = 6;
A = gallery('poisson', n);
f = rand(N, 1);

x = zeros(N, 1);

A
f = f;

r = A*x - f;
eps = 1.e-6;
normf = norm(f);
err = norm(r)/normf;
k = 0;
K_max = 1000;

while(err > eps && k < K_max)
    Ar = A*r;
    tau = (r.'*r)/(Ar.'*r);
    x = x - tau*r;
    r = A*x - f;
    err = norm(r)/normf;
    k = k + 1;
    Err(k) = err;
end

semilogy(1:k, Err)
k
A\f - x