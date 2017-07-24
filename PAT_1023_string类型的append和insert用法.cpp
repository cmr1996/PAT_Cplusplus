#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string num;
	int n0, n;
	cin >> n0;
	for (int i = 1; i < 10; i++)
	{
		cin >> n;

		if (n > 0)
		{
			num.append(n, i + '0'); //n个'i'
		}
	}

	if (n0>0)
	{
		num.insert(1, n0, '0');//insert参数是起始位置、插入个数、插入内容
	}

	cout << num << endl;
	return 0;
}