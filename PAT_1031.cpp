#include<iostream>
#include<string>
using namespace std;

int main()
{
	int weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char M[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	int N;
	string tmp;
	cin >> N;//输入个数
	int ans_cnt = 0;//正确结果计数位

	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		int error = 0;//错误标志位
		cin >> tmp;
		for (int j = 0; j < 17; j++)
		{
			if (tmp[j] >= '0'&&tmp[j] <= '9')
			{
				sum += (tmp[j] - '0')*weight[j];
			}
			else
			{
				error = 1;
				break;
			}
		}

		if (error == 1)
		{
			cout << tmp << endl;
		}
		else
		{
			int Z = sum % 11;
			if (tmp[17] == (M[Z]) )
			{
				ans_cnt++;
			}
			else
			{
				cout << tmp << endl;
			}
		}
	}

	if (ans_cnt == N)
	{
		cout << "All passed" << endl;
	}
	return 0;
}

//用vs2015编译会出现读取一行立刻返回一行的结果，但可以通过PAT官网测试(编译器版本g++ 4.7.3)
