clear;
n = 7;
N = n^2;

A = gallery('poisson',n);

s = abs(eig(A));
L1 = min(s); 
L2 = max(s);
tau = 2/(L1+L2);

f = ones(N, 1);
x = zeros(N, 1);

r = A*x - f;
eps = 1.e-5;
err = norm(r)/norm(f);
err1 = err;
k = 0;
K_max = 1000;

while (err > eps && k < K_max)
    x = x- tau*r;
    r = A*x - f;
    err = norm(r)/norm(f);
    k=k + 1;
    Err(k) = err;
end

tau2 = 1/normest(A);
k1 = 0;
x = zeros(N, 1);

while (err1 > eps && k1 < K_max)
    x = x- tau2*r;
    r = A*x - f;
    err1 = norm(r)/norm(f);
    k1 = k1 + 1;
    Err1(k1) = err1;
end

semilogy(1:k1, Err1, 1:k, Err);
xlabel('k');
ylabel('||r^{k}||/||f^{k}||')
grid
legend('1','2')
