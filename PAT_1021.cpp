#include<iostream>
#include<string>
using namespace std;

int main()
{
	string num;
	int cnt[10] ;
	for (int i = 0; i < 10; i++)
	{
		cnt[i] = -1;
	}
	getline(cin, num);

	for (int i = 0; i<num.size(); i++)
	{
		if (cnt[(num[i] - '0')] == -1)
		{
			cnt[(num[i] - '0')] += 2;
		}
		else
		{
			cnt[(num[i] - '0')]++;
		}
	}

	for (int i = 0; i<10; i++)
	{
		if (cnt[i] != -1)
		{
			cout << i << ":" << cnt[i] << endl;
		}
	}
	return 0;
}