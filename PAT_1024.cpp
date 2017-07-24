#include<iostream>
#include<string>
using namespace std;

//+1.23400E-03
//+(0)1(1).(2)23400(*)E(flag_E)-(flag2=flag_E+1)03(falg2+1~end)
int main()
{
	string regular;
	getline(cin, regular);
	if (regular[0]=='-')
	{
		cout << "-";
	}
	int E_index = regular.find('E');
	char exp_flag = regular[E_index + 1];
	string exp = regular.substr(E_index+2);
	int EXP = atoi(exp.c_str());//获取指数
	string num_str = regular.substr(3, E_index - 3);

	string ans;
	ans = regular[1] + num_str;
	if (exp_flag=='-')
	{
		for (int i = 0; i < EXP-1; i++)
		{
			ans = "0" + ans;
		}
		ans = "0." + ans;
	}
	else
	{
		if (E_index-3>EXP)
		{
			ans.insert(EXP + 1, ".");
		}
		else
		{
			for (int i = 0; i < EXP - E_index + 3; i++)
			{
				ans += "0";
			}
		}
	}

	cout << ans;
	return 0;
}