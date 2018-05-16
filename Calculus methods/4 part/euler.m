clear;
clc;
f=@(x,y)+(1+x.*y)./x^2;
u=@(x)+1/2*(x-1./x);
y0=0;
x0=1;
xn=2;
n=20;
h=(xn-x0)/n;
X=x0:h:xn;
Y=zeros(1,n+1);
Y(1)=y0;
U=u(X);

for i=1:n
Y(i+1)=Y(i)+h*f(X(i),Y(i));
end;
plot(X,U,'r.',X,Y,'b.-');
legend('ES','Euler');
