clear all
clc
sigma=10;
beta=8/3;
rho=28;

opts=odeset('RelTol',1e-9);
u0=[3;0];
T=20;
span=[0 T];
f1 = @(t,u) [u(2);-9*sin(u(1))];

tic
[t,U45]=ode45(f1,span,u0,opts);
t_ode45=toc;

tic
[t1,U113]=ode113(f1,span,u0,opts);
t_ode113=toc;

ta=0:0.01:T

subplot(2,1,1)
plot(t,U45(:,1),'-o',t1,U113(:,1),'r-')
subplot(2,1,2)
plot(t,U45(:,2),'-o',t1,U113(:,2),'r-')

tol=[1.e-20,1.e-30,1.e-35]
for i=1:3

opts=odeset('RelTol',tol(i));
tic
[t,U45]=ode45(f1,span,u0,opts);
t_ode451(i)=toc;

tic
[t1,U113]=ode113(f1,span,u0,opts);
t_ode1131(i)=toc;

end

tt=1:1:3
figure
loglog(tol,t_ode451,'-o',tol,t_ode1131,'r-')
legend('45','113')
