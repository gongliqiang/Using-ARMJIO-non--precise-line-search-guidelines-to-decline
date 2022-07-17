#include<iostream>
#include"Eigen/Dense"
#include"grad.h"
#include"Myfun.h"
#include"Armjio.h"
using namespace std;
using namespace Eigen;
//k = 0;                  % 统计迭代次数
//xk = x0;
//gk = feval(grad, xk);
//while k <= kmax
//if norm(gk) < eps
//	break;
//end
//dk = -gk;            % 选取此处的负梯度方向作为下降方向
//% 采用 Armjio 准则求步长
//alpha = armjio("MyFun", "grad", xk, dk);
//xk = xk + alpha * dk; % 更新迭代点
//gk = feval(grad, xk); % 更新梯度值
//k = k + 1;
//end
//f = feval(MyFun, xk);
int main() {
	int N=10;//N决定x的维度
	int k = 0, kmax = 1000000;
	float eps = 1e-4;
	//VectorXd x0(N);
	VectorXf x0=VectorXf::Random(N, 1);
	/*Vector2d x0;
	x0 << -1, 0.2;*/
	VectorXf xk = x0;
	Grad Grad;
	VectorXf gk = Grad.grad(xk);
	while (k<kmax)
	{
		if (gk.norm()<eps)
		{
			break;
		}
		VectorXf dk = -gk;
		Armjio armjio;
		float alpha = armjio.armjio(xk, dk);
		xk = xk + alpha * dk;
		gk = Grad.grad(xk);
		k = k + 1; 
	}
	Myfun MyFun; 
	
	float f = MyFun.myFun(xk);
	cout << "x0=" << x0 << endl;
	cout << "迭代次数为" << k << endl;
	cout << "令我的 function最小的x为" << xk << endl;
	cout << "最小值为" << f << endl;

}
