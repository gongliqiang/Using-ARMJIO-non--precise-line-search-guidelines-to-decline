#pragma once
#include <numeric>
#include <vector>
#include"Eigen/Dense"
using namespace std;

//function fun = MyFun(x)
//f = zeros(1, length(x));
//for i = 1:length(x)
//if ((mod(i, 2) == 0))
//f(i / 2) = (100 * (x(i - 1) ^ 2 - x(i)) ^ 2 + (x(i - 1) - 1) ^ 2);
//end
//end
//fun = sum(f);
class Myfun {
public:
	float myFun(VectorXf &x) {
		int n = x.size()/2;
		double f;
		VectorXf fun(n);
		for (int i = 0; i < x.size(); i++) {
			if (i % 2 != 0&&i!=0) {
				fun(i / 2)= 100 * pow((pow(x(i - 1), 2) - x(i)) , 2)+ pow(x(i - 1) - 1,  2);
			}
		}
		f = fun.sum();
		return f;

	}
};
