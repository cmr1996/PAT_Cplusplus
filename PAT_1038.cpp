#include<iostream>
using namespace std;

int main()
{
	int n;
	int grade[100001];
	cin >> n;
	for (int  i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (grade[k]<0)
		{
			grade[k] = 1;
		}
		else
		{
			grade[k]++;
		}
	}

	int n_ans;
	cin >> n_ans;
	if (n_ans==1)
	{
		int tmp;
		cin >> tmp;
		cout << grade[tmp];
	}
	else
	{
		for (int i = 0; i < n_ans - 1; i++)
		{
			int tmp1;
			cin >> tmp1;
			cout << grade[tmp1] << " ";
		}
		int k1, k2;
		cin >> k1;
		cout << grade[k1];
	}
}