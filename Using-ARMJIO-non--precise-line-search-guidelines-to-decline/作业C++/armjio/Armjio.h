
#include"Eigen/Dense"
#include"grad.h"
#include"Myfun.h"

using namespace std;
#pragma once
//%% 非精确线性搜索求步长MATLAB
//beta = 0.333; 		    % 步长 alpha 的迭代系数，小于 1
//c = 1e-3; 		        % 泰勒展开式补足系数，0 < c < 1 / 2
//	alpha = 1; 			    % 初始步长为 1
//	k = 0; 				    % 统计迭代次数
//	gk = feval(grad, x0);	% x0处的梯度值
//	fd = feval(MyFun, x0 + alpha * dk); 	            % 函数在下一个迭代点处的目标函数值
//	fk = feval(MyFun, x0) + alpha * c * gk' * dk; 	%  函数在下一个迭代点处的泰勒展开值
//	while fd > fk
//		alpha = beta * alpha;
//fd = feval(MyFun, x0 + alpha * dk);
//fk = feval(MyFun, x0) + alpha * c * gk' * dk;
//k = k + 1;
//end
//xk = x0 + alpha * dk;	% 下降点
//f = feval(MyFun, xk);	% 下降点处函数值
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

