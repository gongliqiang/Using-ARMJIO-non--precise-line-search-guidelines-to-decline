# Using-ARMJIO-non--precise-line-search-guidelines-to-decline
采用Armjio非精确线搜索准则的最速下降法--C++和MATLAB实现
#Readme：
1、MATLAB代码
1、在该解压缩的路径下，在命令行窗口输入：
clear； x0=randn(50,1);eps=1e-5;kmax=20000;
[f, xk, k] = SD(x0, "MyFun", "grad", eps, kmax)
2、C++代码
直接运行SD.CPP，通过定义N定义维度
#代码实现功能：
1、任意维度的Rosenbrock function都可以使用armijo准则的线性搜索优化到最小值。（x0可以定义为任意维度，x0为偶数）。
2、算法适用任意function调用该算法，但需要你给出问题本身的function和梯度函数。（[f, xk, k] = SD(x0, "MyFun", "grad", eps, kmax)，这里的MyFun和grad可以自己给定）。
3、MATLAB和C++的实现
