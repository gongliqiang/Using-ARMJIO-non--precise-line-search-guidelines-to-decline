function [alpha, xk, f, k] = armjio(MyFun, grad, x0, dk)
% clear;clc;close all;
%% �Ǿ�ȷ���������󲽳�
beta = 0.333; 		    % ���� alpha �ĵ���ϵ����С�� 1��Խ��Խ��
c = 0.45; 		        % ̩��չ��ʽ����ϵ����0 < c < 1/2 ,Խ��Խ�죨�����Ծ���������������
alpha = 1; 			    % ��ʼ����Ϊ 1
k = 0; 				    % ͳ�Ƶ�������
gk = feval(grad,x0);	% x0�����ݶ�ֵ
fd = feval(MyFun,x0 + alpha * dk); 	            % ��������һ�������㴦��Ŀ�꺯��ֵ
fk = feval(MyFun,x0) + alpha * c * gk' * dk; 	%  ��������һ�������㴦��̩��չ��ֵ
while fd > fk
    alpha = beta * alpha;
    fd = feval(MyFun,x0 + alpha * dk);
    fk = feval(MyFun,x0) + alpha * c * gk' * dk;
    k = k + 1;
end
xk = x0 + alpha * dk;	% �½���
f = feval(MyFun, xk);	% �½��㴦����ֵ