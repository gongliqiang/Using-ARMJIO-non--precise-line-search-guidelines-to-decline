#include<iostream>
#include"Eigen/Dense"
#include"grad.h"
#include"Myfun.h"
#include"Armjio.h"
using namespace std;
using namespace Eigen;
//k = 0;                  % ͳ�Ƶ�������
//xk = x0;
//gk = feval(grad, xk);
//while k <= kmax
//if norm(gk) < eps
//	break;
//end
//dk = -gk;            % ѡȡ�˴��ĸ��ݶȷ�����Ϊ�½�����
//% ���� Armjio ׼���󲽳�
//alpha = armjio("MyFun", "grad", xk, dk);
//xk = xk + alpha * dk; % ���µ�����
//gk = feval(grad, xk); % �����ݶ�ֵ
//k = k + 1;
//end
//f = feval(MyFun, xk);
int main() {
	int N=10;//N����x��ά��
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
	cout << "��������Ϊ" << k << endl;
	cout << "���ҵ� function��С��xΪ" << xk << endl;
	cout << "��СֵΪ" << f << endl;

}
