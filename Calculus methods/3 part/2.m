q = 0;
g = 0;


t1=[];t2=[];
for N=100:100:1000
    a = ones(N,1);
    b = ones(N,1);
    c = a+b;
    f = -b;


    alf = zeros(N, 1);
    bet = zeros(N, 1);

    tic
    for i=2:N-1
        alf(i+1,1) = b(i,1) / (c(i,1) - a(i,1) * alf(i,1));
        bet(i+1,1) = (a(i,1) * bet(i,1) - f(i,1)) / (c(i,1)-a(i,1) * alf(i,1));
    end

    x = zeros(N,1);

    for i=N-1:-1:2
        x(i,1) = alf(i+1,1) * x(i+1,1) + bet(i+1,1);
    end
    t1(round(N/100))=toc;

    tic
    A = spdiags([a(2:N-1), -c(2:N-1), b(2:N-1)], -1:1, N-2, N-2);
    % A = full(A);
    y = A\f(2:N-1);
    y = [0;y;0];
    t2(round(N/100))=toc;
    %plot(1:N, x, 'o', 1:N, y, '*');
end


plot(t1,1:size(t1), '8', t2,1:size(t2), '*');