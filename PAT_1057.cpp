#include<iostream>
#include<string>
using namespace std;

void dec2bir(int sum,int &cnt0,int &cnt1)
{
	int m;
	//int cnt0 = 0, cnt1 = 0;
	while (sum!=0)
	{
		m = sum % 2;
		if (m == 1) { cnt1++; }
		if (m == 0) { cnt0++; }
		sum = sum / 2;
	}
	//return cnt0, cnt1;
}

int main()
{
	int sum = 0;
	string tmp;
	getline(cin, tmp);
	int len = tmp.size();
	for (int i = 0; i < len; i++)
	{
		if (tmp[i] >= 'a' && tmp[i] <= 'z') { sum += tmp[i] - 'a' + 1; }
		if (tmp[i] >= 'A'&&tmp[i] <= 'Z') { sum += tmp[i] - 'A' + 1; }
	}
	int ans0 = 0, ans1 = 0;
	//ans0, ans1 = dec2bir(sum);
	dec2bir(sum, ans0, ans1);
	cout << ans0 << ' ' << ans1;
	return 0;
}