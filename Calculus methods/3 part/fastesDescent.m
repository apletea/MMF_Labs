clc;
clear;

m = 0;
for n = 5:20
    
    m = m + 1;
    N = n^2;

    A = gallery('poisson', n);
    f = rand(N, 1);
    x = zeros(N, 1);

    normf = norm(f);
    r = A*x - f;
    eps = 1.e-6;
    err = norm(r)/normf;

    k_mn = 0;
    K_max = 10000;

    while(err > eps && k_mn < K_max)
        Ar = A*r;
        tau_mn = (Ar.'*r)/(Ar.'*Ar);
        x = x - tau_mn*r;
        r = A*x - f;
        err = norm(r)/normf;
        k_mn = k_mn + 1;
        %Err(k_mn) = err;
    end

    N_mn(m) = k_mn;
    
    x = zeros(N, 1);
    r = A*x - f;
    err = norm(r)/normf;
    
    k_sd = 0;
    while(err > eps && k_sd < K_max)
        Ar = A*r;
        tau_sd = (r.'*r)/(Ar.'*r);
        x = x - tau_sd*r;
        r = A*x - f;
        err = norm(r)/normf;
        k_sd = k_sd + 1;
        %Err_(k_sd) = err;
    end
    
    N_sd(m) = k_sd;
end

plot(5:n, N_sd, 5:n, N_mn)
legend('sd', 'mn');