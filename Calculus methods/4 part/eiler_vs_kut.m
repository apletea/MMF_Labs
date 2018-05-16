%%main.m
clear;
clc;
%начальные данные
a=1;
b=2;
u0=2;
f=@(t,u)1/t^2-u/t-5*u^2; %правая часть уравнения
h=0.1; %первоначальный шаг
eps=1.e-5;

%первый раз получаем решения с помощью метода Эйлера
[t1,u1]=Euler(f,u0,a,b,h);

h=h/2;
[t2,u2]=Euler(f,u0,a,b,h);

k=1;
norma1(k)=max(abs(u1-u2(1:2:end))); %норма разности первого и
%второго решений
He(k)=h;
while(norma1(k)>eps && k<17)
u1=u2
h=h/2
[t2,u2]=Euler(f,u0,a,b,h);

k=k+1;
norma1(k)=max(abs(u1-u2(1:2:end)));
He(k)=h;
end
h_Euler=h %итоговый шаг по Эйлеру
k_Euler=k %итоговое количество делений шага пополам

h=0.05;
eps=1.e-12;
[t1,u1]=ode_rk4(f,u0,a,b,h);
h=h/2;
[t2,u2]=ode_rk4(f,u0,a,b,h);
k=1;
norma2(k)= max(abs(u1-u2(1:2:end)))/(2^4-1);
Hrk(k)=h;
while(norma2(k)>eps && k<30)
u1=u2;
h=h/2
[t2,u2]=ode_rk4(f,u0,a,b,h);
k=k+1;
norma2(k)= max(abs(u1-u2(1:2:end)))/(2^4-1);
Hrk(k)=h;
end
h_rk4=h %итоговый шаг по Р-К
k_rk4=k %итоговое количество делений шага пополам
loglog(He,norma1,Hrk,norma2)
legend('Euler', 'RK')
grid
xlabel('h')
ylabel('Err')

%%Euler.m
function[u,t] = Euler(f,u0,t0,tk,tau)
n=(tk-t0)/tau
t=t0:tau:tk;
u=zeros(1,n+1);
u(1)=u0;

for i=1:n
u(i+1)=u(i)+tau*f(t(i),u(i));
end;
end

%%ode_rk4.m
function [t,u]=ode_rk4(right_side,u0,t0,tk,tau)
t=t0:tau:tk;
u=zeros(size(t));
n=length(t);
u(1)=u0;

for k=1:n-1
k1=tau*right_side(t(k),u(k));
k2=tau*right_side(t(k)+tau/2,u(k)+k1/2);
k3=tau*right_side(t(k)+tau/2,u(k)+k2/2);
k4=tau*right_side(t(k)+tau,u(k)+k3);

u(k+1)=u(k)+1/6*(k1+2*k2+2*k3+k4);
end
end
