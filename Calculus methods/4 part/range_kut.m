%% rightside.m
function[f]=right_side(t,u)
f =(1/t^2)-u/t-1.5*u^2;
end
%% ode_rk4.m
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

%% main.m
clc;
clear;
f=@right_side;
u0=2;
t0=1;
tk=2;
tau=0.1;
[t,u]=ode_rk4(f,u0,t0,tk,tau);


plot(t,u,'r.-');
legend('R-K');
