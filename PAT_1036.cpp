#include<iostream>
using namespace std;

int main()
{
	int n;
	char m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cout << m;
	}
	cout << endl;
	int tmp = n / 2 + n%2;
	for (int i = 0; i <tmp-2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0 || j == n - 1) { cout << m; }
			else { cout << " "; }
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cout << m;
	}
	cout << endl;

	return 0;
}