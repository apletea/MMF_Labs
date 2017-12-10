clear;
n = 7;
N = n^2;
A = gallery('poisson', n);
f = rand(N, 1);
eps = 1.e-8;
K_max = 10000;

%Jacoby
B = diag(diag(A));
%invB = inv(B);
D = B\A;
g = B\f;
x = zeros(N, 1);
k1 = 0;
r = D*x - g;
normg = norm(g);
err1 = norm(r)/normg;

while(err1 > eps && k1 < K_max)
    Ar = A*r;
    tau = (r'*r)/(Ar'*r);
    x = x-tau*r;
    r = D*x - g;
    k1 = k1+1;
    err1 = norm(r)/normg;
    Err1(k1) = err1;
end

%Zeidel
B = triu(A);
%invB = inv(B);
D = B\A;
g = B\f;
x = zeros(N, 1);
k2 = 0;
r = D*x - g;
normg = norm(g);
err2 = norm(r)/normg;

while(err2 > eps && k2 < K_max)
    Ar = A*r;
    tau = (r'*r)/(Ar'*r);
    x = x-tau*r;
    r = D*x - g;
    k2 = k2+1;
    err2 = norm(r)/normg;
    Err2(k2) = err2;
end

%SSR
w = 1.5;
D = diag(diag(A));
R = triu(A)-diag(A);
B = D + w*R;
%invB = inv(B);
g = B\f;
x = zeros(N, 1);
k3 = 0;
r = D*x - g;
normg = norm(g);
err3 = norm(r)/normg;

while(err3 > eps && k3 < K_max)
    Ar = A*r;
    tau = (r'*r)/(Ar'*r);
    x = x-tau*r;
    r = D*x - g;
    k3 = k3+1;
    err3 = norm(r)/normg;
    Err3(k3) = err3;
end

B = diag(diag(A));
[x, flag, relres, iter, resvec] = pcg(A, f, eps, K_max);
[x, flag, relres, iter1, resvec1] = pcg(A, f, eps, K_max, B);

semilogy(1:k1, Err1, 1:k2, Err2, 1:k3, Err3, 1:iter+1, resvec, 1:iter1+1, resvec1);
grid
legend('Jacoby','Zeidel','SSR', 'resvec', 'resvec1' );
