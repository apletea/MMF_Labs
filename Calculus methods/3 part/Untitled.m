B = gallery('poisson', 5);
[L, U, P] = lu(B);
subplot(2,2,1);
spy(B);
subplot(2,2,2);
spy(L);
subplot(2,2,3);
spy(U);

n=5;

A = zeros(n);
for i=1:n
    for j=1:n
        A(i,j) = ((i+j)^3)/(i^2+j^2);
    end;
end;

B = zeros(n,1);
for i=i:n
    B(i, 1) = 1/(n-i+1);
end;

[L, U, P] = lu(A);

f = P*B;


y=zeros(1,n);
y(1,1) = f(1,1);
for i=2:n
    sum = 0;
    for j=1:(i-1)
        sum = sum + L(i,j)*f(j);
    end
    y(i) = f(i) - sum;
end

x(n) = y(n) / U(n,n);
for i=(n-1):-1:1
    sum = 0;
    for j=n:-1:(i+1)
        sum = sum + U(i,j)*x(j);
    end
    x(i) = y(i) / U(i,j) +  sum;
end
