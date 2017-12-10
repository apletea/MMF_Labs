n = 5;
N = n^2';
A = gallery('poisson', n);
spy(A);
full(A);

f = rand(N);
[L, U, P] = lu(A);
Pf = P*f;

%  1-st

y = L/Pf;
x = U/y;

A*x - f


