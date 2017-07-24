#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include <functional>  
using namespace std;

//从数列中获取被覆盖的数
void get_overlap_number(set<int>& st, int n) //st为保存被覆盖值的集合，那位关键数
{
	while (n != 1)
	{
		n = (n % 2) ? ((3 * n + 1) / 2) : (n / 2);
		st.insert(n);
	}
}

int main()
{
	set<int> st;//保存被覆盖数的集合
	set<int> key;//保存关键数的集合
	int total;//输入数组的数量
	cin >> total;
	vector<int> input_num;//保存输入的数组
	for (int i = 0; i<total; i++)
	{
		int num;
		cin >> num;
		input_num.push_back(num);
		get_overlap_number(st, num);
	}

	vector<int> answer;
	for (int i = 0; i < input_num.size(); i++)
	{
		if (st.find(input_num[i])==st.end())
		{
			answer.push_back(input_num[i]);
		}
	}
	sort(answer.begin(), answer.end(), greater<int>());
	for (int i = 0; i < answer.size(); i++)
	{
		if (i!=answer.size()-1)
		{
			cout << answer[i] << ' ';
		}
		else
		{
			cout << answer[i];
		}
	}
	return 0;
}