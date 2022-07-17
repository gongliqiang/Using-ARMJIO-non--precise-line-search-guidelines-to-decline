function [f, xk, k] = SD(x0, MyFun, grad, eps, kmax)
%%���Կ��ӻ���ֻ��ʵ�ֶ�ά�ȸ��ߵĿ��ӻ������ڶ�ά�Ĳ���
if(length(x0)==2)
    for j=1:length(x0)
        X(j)=sym(['X',num2str(j)]);
    end
    F=0;
    for i=1:length(x0)
        if((mod(i,2) == 0))
            F=(100*(X(i-1)^2-X(i))^2+(X(i-1)-1)^2)+F;
        end
    end
    F = matlabFunction(F); % �����ű��ʽת��Ϊ����������ļ�
    % ����������ˮƽ����Ȼ��hold on������������ͼ����ʾ��ÿһ�����������͵��������
    figure(1); clf; ezcontour(F,[-1.5 1.5 -1.5 1.5]); axis equal; hold on
end
%%
k = 0;                  % ͳ�Ƶ�������
xk = x0;
gk = feval(grad, xk)
while k <= kmax
    if norm(gk) < eps
        break;
    end
    dk = -gk;            % ѡȡ�˴��ĸ��ݶȷ�����Ϊ�½�����
    % ���� Armjio ׼���󲽳�
    alpha = armjio("MyFun", "grad", xk, dk)
    xk = xk + alpha * dk; % ���µ�����
    gk = feval(grad, xk) % �����ݶ�ֵ
    plot([x0(1) xk(1)],[x0(2) xk(2)],'ko-');hold on
    refresh
    x0 = xk;
    k = k + 1;
end
f =feval(MyFun,xk);
end