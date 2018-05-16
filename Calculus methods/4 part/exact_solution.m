%%%%%-------
clear
clc
la= -18;
f=@(t,u)la*u;
tochnoe=@(t)expr(la*t)
u0=1;
t0=0;
T=10;
b2=[3/2,-1/2];

tau=1/abs(la);
n=(T-t0)/tau;
y=zeros(2,T/tau);
y(1)=u0;
t=t0:tau:T;

for k=3:T
y(k)=y(k-1)+tau*la*(b2(1)*y(k-1)+b2(2)*y(k-2));
end

k1=tau*(f(t(1),y(1)));
k2=tau*(f(t(1)+tau,y(1)+k1);

y(2)=y(1)+1/2*(k1+k2);

plot(t,y,'.-',t,touchnoe(t),'o-')
legend('1','2')
