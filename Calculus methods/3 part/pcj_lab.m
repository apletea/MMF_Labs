clear;
m = 0;
for n=5:20
    m = m + 1; 
    N = n^2;
    
    A = gallery('poisson', n);
    f = ones(N, 1);
    x = zeros(N, 1);
    
    eps = 1.e-6;
    r = A*x - f;
    Ar = A*r;
    normf = norm(f);
    err = norm(r)/normf;
    
    G = r'*r;
    tau = G / (Ar'*r);
    x = x - tau*r;
    d = r;
    
    K_max = 10000;
    
    k = 0;
    while(err > eps && k < K_max)
        Ar = A*r;
        r = A*x - f;
        G1 = r'*r;
        beta = G1/G;
        
        d = r + beta*d;
        Ad = A*d;
        tau = G1/(Ad.'*d);
        x = x - tau*d;
        
        G = G1;
        k = k + 1;
        err = norm(r)/normf;
    end
    
    K_cg(m) = k;
    
    [Z, X, C, iter] = pcg(A, f, eps, K_max);
    K_pcg(m) = iter;
end

plot(5:n, K_cg, 'o-', 5:n, K_pcg)
legend('cg', 'pcg');