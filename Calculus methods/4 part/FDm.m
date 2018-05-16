clear
clc

N=81; h=1/(N-1);
x=0:h:1;
x0=x(2:end-1); %сетка
Nx=length(x0);
e=ones(Nx,1);
%точное решение на сетке
v=dsolve('D2v=32*(t-0.5)^4- 4*(t-0.5)^2','v(0)=0','v(1)=0');
syms t;
u=subs(v,t,x0);
%вычисление функции правой части
f=@(x)32*(x-0.5).^4- 4*(x-0.5).^2;
%%FDM
A=spdiags([e,-2*e,e],- 1:1,Nx,Nx)/h^2;
b=f(x0);
U=A\b(:);
subplot(2,1,1);
semilogy(x0,abs(U-u(:)),'o')

xlabel('x');
ylabel('Err');
legend('FDM')
grid
FDM_ERR=norm(U-u(:))/norm(u)


X(1)=0;
Z(1)=0;

a01=1;
a02=0;
b01=0;
b02=1;
g01=0
g02=0;
t=f(x);

a=1/(h^2);
b=-2/(h^2);
c=1/(h^2);


for i=1:N-1
X(i+1)= -a/(b+c*X(i));
Z(i+1)= (t(i)-c*Z(i))/(b+c*X(i));
end;

del=b02+a02*X(N);
Y(N)=1/del*(g02-a02*Z(N));

for i=N:-1:2
Y(i-1)=X(i)*Y(i)+Z(i);
end;

Yn=Y(2:N-1);
subplot(2,1,2);
semilogy(x0,abs(Yn-u),'o')

figure
plot(x0,U,'o',x0,u,x0,Yn,'.-')
