
    clear
    clc
    fi=0:0.02:2*pi;
    q=exp(i*fi);

    b2=[3/2,-1/2];
    b3=[23/12,-16/12,5/12];
    b4=[55/24,-59/24,37/24,-9/24];

    z=0;
    for m=1:2
    z=z+b2(m)*q.^(2-m)
    end
    g2=(q.^2-q)./z

    z=0;
    for m=1:3
    z=z+b3(m)*q.^(3-m)
    end
    g3=(q.^3-q.^2)./z;

    z=0;
    for m=1:4
    z=z+b4(m)*q.^(4-m)
    end
    g4=(q.^4-q.^3)./z;

    subplot(2,1,1)
    patch(real(g2),imag(g2),[0.9 0.9 0.99])
    patch(real(g3),imag(g3),[0.8 0.8 0.99])
    patch(real(g4),imag(g4),[0.7 0.7 0.99])
    grid

    xlabel('Re\{\mu\}')
    xlabel('Im\{\mu\}')
    axis([-1.2 0 -1 1])
    text(-0.75,0.15,'m=2')
    text(-0.42,0.15,'m=3')
    text(-0.17,0.15,'m=4')
    title('неявный метод А-В')

Oleg
Oleg 05.03.18

    clear
    clc
    fi=0:0.02:2*pi;
    q=exp(i*fi);

    b2=[3/2,-1/2];
    b3=[23/12,-16/12,5/12];
    b4=[55/24,-59/24,37/24,-9/24];

    z=0;
    for m=1:2
    z=z+b2(m)*q.^(2-m)
    end
    g2=(q.^2-q)./z

    z=0;
    for m=1:3
    z=z+b3(m)*q.^(3-m)
    end
    g3=(q.^3-q.^2)./z;

    z=0;
    for m=1:4
    z=z+b4(m)*q.^(4-m)
    end
    g4=(q.^4-q.^3)./z;

    subplot(2,1,1)
    patch(real(g2),imag(g2),[0.9 0.9 0.99])
    patch(real(g3),imag(g3),[0.8 0.8 0.99])
    patch(real(g4),imag(g4),[0.7 0.7 0.99])
    grid

    xlabel('Re\{\mu\}')
    xlabel('Im\{\mu\}')
    axis([-1.2 0 -1 1])
    text(-0.75,0.15,'m=2')
    text(-0.42,0.15,'m=3')
    text(-0.17,0.15,'m=4')
    title('явный метод А-В')

    fi=0:0.02:2*pi;
    q=exp(i*fi);

    b2=[5/12,8/12,-1/12];
    b3=[9/24,19/24,-5/24,1/24];
    b4=[251/720,646/720,-264/720,106/720,-19/720];

    z=0;
    for m=0:2
    z=z+b2(m+1)*q.^(2-m)
    end
    g2=(q.^2-q)./z

    z=0;
    for m=0:3
    z=z+b3(m+1)*q.^(3-m)
    end
    g3=(q.^3-q.^2)./z;

    z=0;
    for m=0:4
    z=z+b4(m+1)*q.^(4-m)
    end
    g4=(q.^4-q.^3)./z;

    subplot(2,1,2)
    patch(real(g2),imag(g2),[0.9 0.9 0.99])
    patch(real(g3),imag(g3),[0.8 0.8 0.99])
    patch(real(g4),imag(g4),[0.7 0.7 0.99])
    grid

    xlabel('Re\{\mu\}')
    xlabel('Im\{\mu\}')
    axis([-10 0 -4 4])
    text(-0.75,0.15,'m=2')
    text(-0.42,0.15,'m=3')
    text(-0.17,0.15,'m=4')
    title('неявный метод')
