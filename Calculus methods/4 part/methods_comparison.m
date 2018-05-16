clear
clc
%вектор правой части
f=@(t,u) [u(2); -9*u(1)];
T=10;
h=0.01;
u=[0;3]; %ветор начальных значений
N=T/h;
ts=0:h:T;
%матрица для заполнения решения методом Рунге-Кутта
%U(1,:)- u1
%U(2,:)- u2
U=zeros(2,N+1);
U(:,1)=u; %начальные значения

%Runge-Kutty
tic
t = 0:h:T;
for k=1:N-1
k1=f(t(k),U(:,k)).*h;
k2=f(t(k)+h/2,U(:,k)+k1/2).*h;
k3=f(t(k)+h/2,U(:,k)+k2/2).*h;
k4=f(t(k)+h,U(:,k)+k3).*h;

U(:,k+1)=U(:,k)+1/6.*(k1+2*k2+2*k3+k4);
end


RK_Time=toc;


%Adams-Bashfort

u=[0;3];%вектор начальных значений
%матрица для заполнения решения методом Адамса-Башфорта
U1=zeros(2,N+1);
U1(:,1)=u;%начальные значения
%массив правых частей
F=zeros(2,N+1);
%значения f0 в точке (t0,u0)
F(:,1)=f(0,u);

tic
%вычисление решения U1 с помощью метода Адамса-Башфорта


%сначала вычислить первые U1(:,2),U1(:,3),U1(:,4) по методу Рунге-Кутта
%U1(:,1)- 0-ой узел, он уже посчитан - это начальные значения
%здесь также вычисляются правые части F(:,2), F(:,3),F(:,4)
for k=1:3
k1=f(t(k),U1(:,k)).*h;
k2=f(t(k)+h/2,U1(:,k)+k1/2).*h;
k3=f(t(k)+h/2,U1(:,k)+k2/2).*h;
k4=f(t(k)+h,U1(:,k)+k3).*h;

U1(:,k+1)=U1(:,k)+1/6.*(k1+2*k2+2*k3+k4);
F(:,k+1)=f(t(k+1),U1(:,k+1));
end

B=h*[-9/24;37/24;-59/24;55/24]
%следующие узлы
for m=4:N
U1(:,m+1)=U1(:,m) + F(:,m-3:m)*B;
F(:,m+1)=f(t(m+1),U1(:,m+1));
%....
%вычисление по формуле (3) методом Адамса-Башфорта
%....

end
AB_time=toc

%вычисление встроенной функцией ode45

span = [0 T]; %промежуток по t
u=[0;3]; %начальные значения функции u
opts = odeset('RelTol',1e-5,'AbsTol',1e-5); %параметры
[t,y] = ode45(f, span, u,opts); %вызов функции

%сравнение с точным решением в точках сетки ts

yTochn=sin(3*ts);

%графики полученных решений

%U - решение методом Рунге-Кутта
%U1 - решение методом Адамса-Башфорта
%y - решение встроенной функцией ode45
%yTochn - точное решение
figure
plot(ts,U1(1,:),'-o',t,y(:,1),'--',ts,yTochn,'-',ts,U(1,:),'-.','linewidth',1)
legend('AB','ode45','yTochn','RK')
