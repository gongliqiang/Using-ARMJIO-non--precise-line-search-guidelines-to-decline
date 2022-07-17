#pragma once
#include"Eigen/Dense"
#include <numeric>
#include <vector>
using namespace Eigen;
using namespace std;
//function fun = grad(x)
//G = zeros(length(x), 1);
//for i = 1:length(x)
//if ((mod(i, 2) == 0))
//G(i - 1, 1) = (-400 * x(i - 1) * x(i) + 400 * x(i - 1) ^ 3 + 2 * x(i - 1) - 2);
//G(i, 1) = (200 * x(i) - 200 * x(i - 1) ^ 2);
//end
//end
//fun = G;
class Grad {
public:
	//Grad();
	VectorXf grad(VectorXf &x) {
		int n = x.size();
		float a = x[0];
		VectorXf G(n);
		for (int i = 0; i < x.size(); i++) {
			if (i % 2 != 0 && i != 0) {
				G(i-1) = (-400 * x(i - 1) * x(i) + 400 * pow(x(i - 1) , 3) + 2 * x(i - 1) - 2);
				G(i) = 200 * x(i) - 200 * pow(x(i - 1) , 2);

			}
		}
		return G;

	}
};
