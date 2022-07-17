
#include"Eigen/Dense"
#include"grad.h"
#include"Myfun.h"

using namespace std;
#pragma once
//%% �Ǿ�ȷ���������󲽳�MATLAB
//beta = 0.333; 		    % ���� alpha �ĵ���ϵ����С�� 1
//c = 1e-3; 		        % ̩��չ��ʽ����ϵ����0 < c < 1 / 2
//	alpha = 1; 			    % ��ʼ����Ϊ 1
//	k = 0; 				    % ͳ�Ƶ�������
//	gk = feval(grad, x0);	% x0�����ݶ�ֵ
//	fd = feval(MyFun, x0 + alpha * dk); 	            % ��������һ�������㴦��Ŀ�꺯��ֵ
//	fk = feval(MyFun, x0) + alpha * c * gk' * dk; 	%  ��������һ�������㴦��̩��չ��ֵ
//	while fd > fk
//		alpha = beta * alpha;
//fd = feval(MyFun, x0 + alpha * dk);
//fk = feval(MyFun, x0) + alpha * c * gk' * dk;
//k = k + 1;
//end
//xk = x0 + alpha * dk;	% �½���
//f = feval(MyFun, xk);	% �½��㴦����ֵ
class Armjio
{
public:
	float armjio(VectorXf &x, VectorXf &dk) {
		float beta = 0.333;
		float c = 0.4;
		float alpha = 1;
		int k = 0;
		Grad Grad;
		VectorXf gk = -Grad.grad(x);
		Myfun MyFun;
		VectorXf aa = x + alpha * dk;
		float fd = MyFun.myFun( aa);
		float fk = MyFun.myFun(x) + alpha * c * gk.transpose() * dk;
		while (fd>fk)
		{
			alpha = beta * alpha;
			VectorXf bb = x + alpha * dk;
			fd = MyFun.myFun(bb);
			fk = MyFun.myFun(x) + alpha * c * gk.transpose() * dk;
		}
		return alpha;
	}
private:

};

