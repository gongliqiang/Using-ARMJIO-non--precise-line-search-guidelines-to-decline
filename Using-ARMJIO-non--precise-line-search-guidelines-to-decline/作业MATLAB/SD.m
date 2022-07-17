function [f, xk, k] = SD(x0, MyFun, grad, eps, kmax)
%%尝试可视化，只能实现二维等高线的可视化，对于多维的不行
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
    F = matlabFunction(F); % 将符号表达式转换为函数句柄或文件
    % 画出函数的水平集，然后hold on，待会会在这个图上显示出每一个迭代步长和迭代结果噢
    figure(1); clf; ezcontour(F,[-1.5 1.5 -1.5 1.5]); axis equal; hold on
end
%%
k = 0;                  % 统计迭代次数
xk = x0;
gk = feval(grad, xk)
while k <= kmax
    if norm(gk) < eps
        break;
    end
    dk = -gk;            % 选取此处的负梯度方向作为下降方向
    % 采用 Armjio 准则求步长
    alpha = armjio("MyFun", "grad", xk, dk)
    xk = xk + alpha * dk; % 更新迭代点
    gk = feval(grad, xk) % 更新梯度值
    plot([x0(1) xk(1)],[x0(2) xk(2)],'ko-');hold on
    refresh
    x0 = xk;
    k = k + 1;
end
f =feval(MyFun,xk);
end