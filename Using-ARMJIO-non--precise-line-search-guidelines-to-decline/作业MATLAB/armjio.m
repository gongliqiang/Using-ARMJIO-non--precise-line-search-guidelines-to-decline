function [alpha, xk, f, k] = armjio(MyFun, grad, x0, dk)
% clear;clc;close all;
%% 非精确线性搜索求步长
beta = 0.333; 		    % 步长 alpha 的迭代系数，小于 1，越大越慢
c = 0.45; 		        % 泰勒展开式补足系数，0 < c < 1/2 ,越大越快（不绝对具体问题具体分析）
alpha = 1; 			    % 初始步长为 1
k = 0; 				    % 统计迭代次数
gk = feval(grad,x0);	% x0处的梯度值
fd = feval(MyFun,x0 + alpha * dk); 	            % 函数在下一个迭代点处的目标函数值
fk = feval(MyFun,x0) + alpha * c * gk' * dk; 	%  函数在下一个迭代点处的泰勒展开值
while fd > fk
    alpha = beta * alpha;
    fd = feval(MyFun,x0 + alpha * dk);
    fk = feval(MyFun,x0) + alpha * c * gk' * dk;
    k = k + 1;
end
xk = x0 + alpha * dk;	% 下降点
f = feval(MyFun, xk);	% 下降点处函数值