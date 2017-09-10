#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {

	int N,  D;
	double e;
	cin >> N >> e >> D;
	int K;//观察期天数
	int p_unused = 0, unused = 0;//可能闲置，闲置

	for (int i = 0; i < N; i++)
	{
		cin >> K;
		//int GCQ = K / 2;//观察期
		int flag = 0;//条件2标记位
		if (K > D) { flag = 1; }

		int cnt = 0;//低于阈值天数的计数器
		for (int j = 0; j < K; j++)
		{
			double m;
			cin >> m;
			if (m < e) { cnt++; }
		}
		if (cnt > K / 2) { p_unused++; }
		if (cnt > K / 2 && flag) { unused++; p_unused--; }
	}
	double n = N;
	double ans1 = (p_unused / n) * 100, ans2 = (unused / n) * 100;
	cout << fixed << setprecision(1) << ans1 << '%' << ' ';
	cout << fixed << setprecision(1) << ans2 << '%';
	return 0;
}