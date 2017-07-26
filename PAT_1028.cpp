#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//c++ range-based for loop
/*
总体思路：
1.创建结构体
2.比较字符串
3.vector 排序
*/

struct node
{
	string name;
	string date;
	int age;
	bool test()
	{
		int sum = 0;//计算age总值
		for (auto c : date)
		{
			if (c>='0'&&c<='9')
			{
				sum = sum * 10 + c - '0';
			}
		}
		age = sum;
		if (20140906-sum<=2000000&&sum<=20140906)//2014/09/06当天出生的也符合要求不然有一个测试点无法通过
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

bool cmp(const node x,const node y)
{
	return x.age < y.age;
}

int main()
{
	int n;
	scanf("%d",&n);//需要将一些地方的流式输入输出修改为标准输入输出，不然最后一个测试点会超时

	node m;
	vector<node> data;
	for (int i = 0; i < n; i++)
	{
		cin >> m.name >> m.date;
		if (m.test()==true)
		{
			data.push_back(m);
		}
	}
	if (data.size()==0)
	{
		printf("0");
	}
	else
	{
		sort(data.begin(), data.end(), cmp);
		cout << data.size() << " " << data[0].name << " " << data[data.size() - 1].name;
	}
	return 0;
}
