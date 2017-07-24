#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

//sort规则重载
bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	string NUM;
	getline(cin, NUM);
	int num;
	num = stoi(NUM);
	if (num%1111==0)
	{
		cout << num << " - " << num << " = 0000" << endl;
	}
	else
	{
		do
		{
			while (NUM.size()<4)
			{
				NUM = "0" + NUM;
			}
			//倒序
			sort(NUM.begin(), NUM.end(), cmp);
			int s1 = stoi(NUM);

			//正序
			sort(NUM.begin(), NUM.end());
			int s2 = stoi(NUM);

			num = s1 - s2;
			string K = to_string(num);
			while (K.size()<4)
			{
				K = "0" + K;
			}
			cout << s1 << " - " << NUM << " = " << K << endl;
			NUM = to_string(num);
		} while (num!=6174);
	}
	return 0;
}