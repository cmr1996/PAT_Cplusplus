#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	long A, B, C;
	int D;
	cin >> A >> B >> D;
	C = A + B;
	vector<int> num;
	while (C/D!=0||C%D!=0)
	{
		int k = C%D;
		num.push_back(k);
		C = C / D;
	}
	
	std::reverse(num.begin(), num.end());
	std::vector<int>::iterator iter;
	if (num.size()==0)
	{
		cout << "0";
	}
	else
	{
		for (iter = num.begin(); iter != num.end(); iter++)
		{
			cout << *iter;
		}
	}
	return 0;
}