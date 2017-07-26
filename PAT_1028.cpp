#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//c++ range-based for loop
struct node
{
	string name;
	string date;
	int age;
	bool test()
	{
		int sum = 0;//¼ÆËãage×ÜÖµ
		for (auto c : date)
		{
			if (c>='0'&&c<='9')
			{
				sum = sum * 10 + c - '0';
			}
		}
		age = sum;
		if (20140906-sum<=2000000&&sum<20140906)
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
	cin >> n;

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
	sort(data.begin(), data.end(), cmp);

	cout << data.size() << " " << data[0].name << " " << data[data.size()-1].name;
	return 0;
}