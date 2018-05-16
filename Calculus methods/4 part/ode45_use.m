clear all
clc
a=4;
b=2.5;
c=2;
d=1;
T=20;
span=[0 T];

opts=odeset('RelTol',1e-6);
f = @(t,x) [(a-b*x(2))*x(1);(-c+d*x(1))*x(2)];

[X,Y] = meshgrid(-1:.5:7)
x1=(a-b.*Y)*X;
x2=(-c+d.*X)*Y;

x0=[[3, 1],[4, 2],[5, 3]];
x01=[3, 1];
x02=[4, 2];
x03=[5, 3];


[t1_45,x1_45]=ode45(f, span, x01, opts);
[t2_45,x2_45]=ode45(f, span, x02, opts);
[t3_45,x3_45]=ode45(f, span, x03, opts);

x11=x1_45(:,1);
x21=x1_45(:,2);
x12=x2_45(:,1);
x22=x2_45(:,2);
x13=x3_45(:,1);
x23=x3_45(:,2);

plot3(t1_45,x11,x21)


figure
subplot(2,1,1)
plot(t1_45,x1_45(:,1),'-r',t1_45,x1_45(:,2),'-b')
subplot(2,1,2)
plot(x11,x21)
hold on
plot(x12,x22)
hold on
plot(x13,x23)
hold on
quiver(X,Y,x1,x2)
