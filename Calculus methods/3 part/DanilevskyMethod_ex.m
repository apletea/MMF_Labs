clear;
clc;
n = 4;
D = [4,3,2,1;3,6,4,2;2,4,6,3;1,2,3,4];
B = [1,0,0,1;0,1,1,0;0,1,1,0;1,0,0,1];
k = 2;
A = D + k*B;
%��� �������� [V,D]=eig(A); V - ������� � ���������, D - �� ���������
%������. ��������

[V,D] = eig(A);
V;
D;

S = eye(n); %���������
%M3^-1 = M33
M33 = eye(n);
M33(3,:) = A(4,:);
M3 = inv(M33);
A = M33*A*M3;
S = S*M3;

M22 = eye(n);
M22(2,:) = A(3,:);
M2 = inv(M22);
A = M22*A*M2;
S = S*M2;

M11 = eye(n);
M11(1,:) = A(2,:);
M1 = inv(M11);
A = M11*A*M1;
S = S*M1;

F = A; %������� ����������

%��������� ���������� ���������� p - ��������� x - �����. �����.
syms p x

p(x) = x^4 - F(1,1)*x^3-F(1,2)*x^2-F(1,3)*x - F(1,4)

l = double(solve(p==0));
l = sort (l, 'ascend')

X = zeros(n, n);
for j=1:4
    y = zeros(n,1);
    y(end) = 1;
    for i=1:n-1
        y(end-i)=l(j)^i;
    end
    X(:,j) = S*y;
end
%������������

for i=1:4
    X(:,i)=X(:,i)/norm(X(:,i));
end
X
V