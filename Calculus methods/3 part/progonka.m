clear;
clc;
% доработка задать массив вместо N, получить разные значения Time_sweep и
% Time_backslash для каждого N, нарисвать график semilogy(N, Time-sweep, N, Time_backslash)
N = 10000;
%x(1) = x(n) = 0 (потому что взяли такие же q)

a = ones(N, 1);
b = a;
c = a + b;

alp = zeros(N, 1);
bet = alp;

alp(2) = 0;
bet(2) = 0;
f = -1 * ones(N, 1);

tic
    for m=2:N
        alp(m+1) = (b(m)) /( c(m) - a(m)*alp(m));
        bet(m+1) = (a(m)*bet(m)-f(m) ) / (c(m) - a(m)*alp(m));
    end
    
    x(N) = 0;
    
    for m=N-1:-1:1
        x(m) = alp(m+1) * x(m+1) + bet(m+1);
    end
Time_sweep = toc

x;

%spdiags строит диагональную матрицу
% первая и последняя строка матрицы А равны 0, поэтому их не добавляем (N-2, N-2)
A = spdiags([a(2:N-1),-c(2:N-1),b(2:N-1)], -1:1, N-2, N-2);
full(A);
F = f(2:N-1);

tic
    X = A\F;
Time_backslash = toc

X = [0; X; 0];

plot(1:N, x, '.', 1:N, X, 'o')
legend('sweep', 'backslash');


